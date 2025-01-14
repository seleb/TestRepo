#pragma once

#include "shader/SharedComponentShaderMethods.h"
#include "RenderOptions.h"
#include "MatrixStack.h"
#include "node/NodeRenderable.h"
#include "GLUtils.h"
#include "MeshInterface.h"
#include "Material.h"
#include "Transform.h"

void SharedComponentShaderMethods::configureLights(vox::MatrixStack* _matrixStack, RenderOptions * _renderOption, NodeRenderable* _nodeRenderable){
	MeshInterface * mesh = dynamic_cast<MeshInterface *>(_nodeRenderable);
	if(mesh != nullptr){
		// Pass the _shader the number of lights
		if(_renderOption->lights->size() != _renderOption->lastNumLights){
			_renderOption->lastNumLights = _renderOption->lights->size();
			glUniform1i(glGetUniformLocation(_renderOption->shader->getProgramId(), GL_UNIFORM_ID_NUM_LIGHTS.c_str()), _renderOption->lights->size());
		}
		// Pass the paramaters for each light to the _shader
		for(unsigned long int i = 0; i < _renderOption->lights->size(); i++){
			Light * l = _renderOption->lights->at(i);
			glm::vec3 curPos = l->getPos(false);
			//std::cout << curPos.y << " " << l->data.lastPos.y << std::endl;
			if(l->lastPos != curPos){
				l->lastPos = curPos;
				l->dirty = true;
			}if(l->lastData != l->data){
				l->lastData = l->data;
				l->dirty = true;
			}

			if(l->dirty){
				//std::cout << "update light " << i << ": " << curPos.x << "," << curPos.y << "," << curPos.z << std::endl;
				std::string typ = GLUtils::buildGLArrayReferenceString(GL_UNIFORM_ID_LIGHTS_NO_ARRAY + "[].type", i);
				std::string pos = GLUtils::buildGLArrayReferenceString(GL_UNIFORM_ID_LIGHTS_POSITION, i);
				std::string ins = GLUtils::buildGLArrayReferenceString(GL_UNIFORM_ID_LIGHTS_INTENSITIES, i);
				std::string amb = GLUtils::buildGLArrayReferenceString(GL_UNIFORM_ID_LIGHTS_NO_ARRAY + "[].ambientCoefficient", i);
				std::string att = GLUtils::buildGLArrayReferenceString(GL_UNIFORM_ID_LIGHTS_NO_ARRAY + "[].attenuation", i);
				std::string cut = GLUtils::buildGLArrayReferenceString(GL_UNIFORM_ID_LIGHTS_NO_ARRAY + "[].cutoff", i);
				GLuint typeUniformLocation = glGetUniformLocation(_renderOption->shader->getProgramId(), typ.c_str());
				glUniform1i(typeUniformLocation, static_cast<int>(l->data.type));
				GLuint positionUniformLocation = glGetUniformLocation(_renderOption->shader->getProgramId(), pos.c_str());
				glUniform3f(positionUniformLocation, curPos.x, curPos.y, curPos.z);
				GLuint intensitiesUniformLocation = glGetUniformLocation(_renderOption->shader->getProgramId(), ins.c_str());
				glUniform3f(intensitiesUniformLocation, l->data.intensities.x, l->data.intensities.y, l->data.intensities.z);
				GLuint ambientUniformLocation = glGetUniformLocation(_renderOption->shader->getProgramId(), amb.c_str());
				glUniform1f(ambientUniformLocation, l->data.ambientCoefficient);
				GLuint attenuationUniformLocation = glGetUniformLocation(_renderOption->shader->getProgramId(), att.c_str());
				glUniform1f(attenuationUniformLocation, l->data.attenuation);
				GLuint cutoffUniformLocation = glGetUniformLocation(_renderOption->shader->getProgramId(), cut.c_str());
				glUniform1f(cutoffUniformLocation, l->data.cutoff);
				l->dirty = false;
			}
		}
	}
}

void SharedComponentShaderMethods::configureMaterials(vox::MatrixStack* _matrixStack, RenderOptions* _renderOption, NodeRenderable* _nodeRenderable){
	MeshInterface * mesh = dynamic_cast<MeshInterface *>(_nodeRenderable);
	if(mesh != nullptr){
		// Pass the _shader the number of materials
		glUniform1i(glGetUniformLocation(_renderOption->shader->getProgramId(), GL_UNIFORM_ID_NUM_MATERIALS.c_str()), mesh->materials.size());

		// Pass each material to the _shader
		for(unsigned long int i = 0; i < mesh->materials.size(); i++){
			std::string shin = GLUtils::buildGLArrayReferenceString(GL_UNIFORM_ID_MATERIALS_NO_ARRAY+"[].shininess", i);
			std::string spec = GLUtils::buildGLArrayReferenceString(GL_UNIFORM_ID_MATERIALS_NO_ARRAY+"[].specularColor", i);
			GLuint shinyUniformLocation = glGetUniformLocation(_renderOption->shader->getProgramId(), shin.c_str());
			GLuint specColorUniformLocation = glGetUniformLocation(_renderOption->shader->getProgramId(), spec.c_str());
			glUniform1f(shinyUniformLocation, mesh->materials.at(i)->data.shininess);
			glUniform3f(specColorUniformLocation, mesh->materials.at(i)->data.specularColor.x, mesh->materials.at(i)->data.specularColor.y, mesh->materials.at(i)->data.specularColor.z);
		}
	}
}