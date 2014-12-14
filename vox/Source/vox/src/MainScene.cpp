#pragma once

#include "MainScene.h"
#include "Resource.h"
#include "FakeAnimation.h"
#include "Texture.h"
#include "Material.h"
#include "FrameBufferChannel.h"
#include "StandardFrameBuffer.h"
#include "DepthFrameBuffer.h"
#include "RenderSurface.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "VoxRenderOptions.h"
#include "PerspectiveCamera.h"
#include "OrthographicCamera.h"
#include "shader/BaseComponentShader.h"
#include <shader/DiffuseShaderComponent.h>
#include <shader/ShadowShaderComponent.h>
#include <shader/TextureShaderComponent.h>
#include <VoxelJoint.h>
#include "shader/PhongShaderComponent.h"
#include "shader/BlinnShaderComponent.h"
#include "Transform.h"
#include "shader/DepthMapShader.h"
#include "shader/VoxelComponent.h"
#include "MeshEntity.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "MeshInterface.h"

Cube * cube;
Cube * cube2;
Cube * cube3;
Cube * cube4;

Texture * tex;
Texture * voxTex;

Material * mat;
Material * bMat;

Shader * texShader;
Shader * phongShader;
Shader * blinnShader;
Shader * voxShader;

DirectionalLight *tLight;

StandardFrameBuffer * frameBuffer;

RenderSurface * renderSurface;

Entity * loaded1;

Transform * t;

BaseComponentShader * baseShader;
VoxelJoint * voxelJoint;

MainScene::MainScene(Game * _game):
	Scene(game)
{
	frameBuffer = new StandardFrameBuffer(true);
	frameBuffer->checkFrameBufferStatus();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	renderSurface = new RenderSurface(new Shader("../assets/RenderSurface", false, true));

	texShader = new Shader("../assets/diffuse", false, true);

	phongShader = new Shader("../assets/phong", false, true);
	blinnShader = new Shader("../assets/blinn", false, true);

	voxShader = new Shader("../assets/voxel", true, true);

	tex = new Texture("../assets/uv-test.jpg", 1000, 1000, true, true);
	voxTex = new Texture("../assets/voxel-texture.png", 512, 512, true, true);

	baseShader = new BaseComponentShader();
	
	baseShader->components.push_back(new DiffuseShaderComponent());
	baseShader->components.push_back(new BlinnShaderComponent());
	baseShader->components.push_back(new ShadowShaderComponent());
	baseShader->components.push_back(new TextureShaderComponent());
	baseShader->compileShader();

	voxelShader = new BaseComponentShader();
	voxelShader->components.push_back(new TextureShaderComponent());
	voxelShader->components.push_back(new DiffuseShaderComponent());
	voxelShader->components.push_back(new PhongShaderComponent());
	voxelShader->components.push_back(new ShadowShaderComponent());
	voxelShader->geometryComponent = new VoxelComponent();
	voxelShader->compileShader();

	mat = new Material(80.0, glm::vec3(1.f, 1.f, 1.f), true);
	bMat = new Material(10.0, glm::vec3(0.5f, 0.1f, 0.9f), true);

	t = new Transform();
	t->translate(-2.f, 0, 0);
	t->scale(3, 3, 3);

	cube = new Cube(glm::vec3(0.f, 0.f, 0.5f),0.2f);
	cube->setShader(baseShader, true);
	cube->transform->translate(0.5f, 0 ,0);
	cube->mesh->vertices.at(3).y += 1.5;
	cube->mesh->vertices.at(0).y += 1.5;
	static_cast<QuadMesh *>(cube->mesh)->pushQuad(2,1,5,7);

	for(unsigned long int i = 0; i < 1; ++i){
		MeshEntity * loaded = new MeshEntity(Resource::loadMeshFromObj("../assets/cube.vox"), t, voxelShader);
		loaded->mesh->polygonalDrawMode = GL_POINTS;
		loaded->mesh->pushMaterial(mat);
		//cube->addChild(loaded);
		loaded->mesh->pushTexture2D(tex);
	}

	MeshEntity * loaded1 = new MeshEntity(Resource::loadMeshFromObj("../assets/cube.vox"), t, baseShader);
	cube->addChild(loaded1);
	loaded1->mesh->pushMaterial(mat);

	cube2 = new Cube(glm::vec3(0.f, 0.f, 0.5f),1);
	cube2->setShader(texShader, true);
	cube2->transform->translate(0.5f, 0.f, 0.f);
	cube2->mesh->pushTexture2D(tex);

	cube3 = new Cube(glm::vec3(0.f, 0.f, 0.5f),1);
	cube3->transform->scale(1, 10, 1);
	cube3->transform->translate(0.f, 5.f, 0.f);
	cube->addChild(cube2);
	addChild(cube3);
	cube3->setShader(texShader, true);
	cube3->transform->translate(0.5f, 0.f, 0.f);
	cube3->mesh->pushTexture2D(tex);

	cube3->mesh->pushMaterial(bMat);
	cube3->transform->translate(5, 0 ,0);

	cube4 = new Cube(glm::vec3(0.f, 0.f, 0.5f),1);
	addChild(cube);
	addChild(cube4);
	cube4->setShader(baseShader, true);
	cube4->transform->scale(15.0, 1.0, 15.0);
	cube4->transform->translate(0, -2, 0);
	cube4->mesh->pushTexture2D(tex);
	cube4->mesh->pushMaterial(mat);

	cube->mesh->dirty = true;
	cube2->mesh->dirty = true;
	cube3->mesh->dirty = true;
	cube4->mesh->dirty = true;
	loaded1->mesh->dirty = true;

	tLight = new DirectionalLight(glm::vec3(1.f, 0.8f, 0.6f),
		glm::vec3(1.0f, 0.0f, 0.f),
		0.06f);

	PointLight * tLight2 = new PointLight(glm::vec3(1.f, -1.5, 1.f),
		glm::vec3(0.1f, 0.2f, 0.8f),
		0.2f,
		0.005f);

	tLight2->transform->translate(-2,0,0);
	tLight->transform->translate(2,0,0);
	lights.push_back(tLight);
	lights.push_back(tLight2);

	FakeAnimation * cat = new FakeAnimation(new Transform(), texShader);
	/*cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/01.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/02.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/03.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/04.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/05.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/06.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/07.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/08.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/09.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/10.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/11.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/12.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/13.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/14.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/15.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/16.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/17.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/18.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/19.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/20.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/21.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/22.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/23.vox")));
	cat->pushFrame(new Entity(Resource::loadMeshFromObj("../assets/CatThing/24.vox")));*/

	for(Node * e : cat->children){
		dynamic_cast<MeshEntity *>(e)->mesh->polygonalDrawMode = GL_POINTS;
	}

	cat->transform->translate(1, 0, 2);
	cat->transform->scale(0.9f, 0.9f, 0.9f);
	//addChild(cat);
	

	voxelJoint = Resource::loadVoxelModel("A:/test.json");
	voxelJoint->setShaderOnChildren(voxShader);
	voxelJoint->transform->translate(5.f, 0.f, 0.f);

	addChild(voxelJoint);

}

MainScene::~MainScene(){
}

void MainScene::update(){
	Scene::update();

	voxelJoint->update(&vox::step);

	//tLight->transform->translateX(sinf((float)glfwGetTime()) * 0.1f * (float)vox::deltaTimeCorrection);
	//tLight->transform->translateZ(cosf((float)glfwGetTime()) * 0.1f * (float)vox::deltaTimeCorrection);

	if(keyboard->keyJustUp(GLFW_KEY_F11)){
		toggleFullScreen();
	}
	if(keyboard->keyDown(GLFW_KEY_A)){
		cube->transform->rotate(2.f, 0.f, -1.f, 0.f, kOBJECT);
		cube3->transform->translate(-0.2f, 0.f, 0.f);
	}
	if(keyboard->keyDown(GLFW_KEY_D)){
		cube2->transform->translate(0.02f, 0.f, 0.f);
		cube2->transform->rotate(2.f, 0.f, -1.f, 0.f, kOBJECT);

		cube3->transform->translate(0.2f, 0.f, 0.f);
	}
	if(keyboard->keyDown(GLFW_KEY_S)){
		cube->transform->rotate(2.f * (float)vox::deltaTimeCorrection , 1.f, 0.f, 0.f, kOBJECT);
		cube3->transform->translate(0.f, 0.f, -0.2f);
	}
	if(keyboard->keyDown(GLFW_KEY_W)){
		cube->transform->rotate(2.f, -1.f, 0.f, 0.f, kOBJECT);
		cube3->transform->translate(0.f, 0.f, 0.2f);
	}
	if(keyboard->keyDown(GLFW_KEY_Q)){
		cube3->transform->translate(0.02f, 0.f, 0.f);
		cube3->transform->rotate(2.f, 0.f, -1.f, 0.f, kOBJECT);
	}
	if(keyboard->keyDown(GLFW_KEY_E)){
		cube->transform->translate((float)vox::deltaTimeCorrection * 0.01f, 0.f, 0.f);
	}
	if(mouse->leftDown()){
		glm::quat r = glm::angleAxis(1.f, glm::vec3(0.f, 0.f, 1.f));
		cube->transform->rotate(r, kOBJECT);
	}
	if(mouse->rightDown()){
		cube->transform->scale(0.9f, 0.9f, 0.9f);
	}
	//camera controls
	if (keyboard->keyDown(GLFW_KEY_UP)){
		camera->transform->translate((camera->forwardVectorRotated) * camera->speed);
	}
	// Move backward
	if (keyboard->keyDown(GLFW_KEY_DOWN)){
		camera->transform->translate((camera->forwardVectorRotated) * -camera->speed);
	}
	// Strafe right
	if (keyboard->keyDown(GLFW_KEY_RIGHT)){
		camera->transform->translate((camera->rightVectorRotated) * camera->speed);
	}
	// Strafe left
	if (keyboard->keyDown(GLFW_KEY_LEFT)){
		camera->transform->translate((camera->rightVectorRotated) * -camera->speed);
	}
	//shininess
	if (keyboard->keyDown(GLFW_KEY_O)){
		mat->data.shininess++;
	}
	if (keyboard->keyDown(GLFW_KEY_L)){
		mat->data.shininess--;
	}
}

void MainScene::render(vox::MatrixStack * _matrixStack, RenderOptions * _renderStack){
	/**int width, height;
	glfwGetFramebufferSize(glfwGetCurrentContext(), &width, &height);

	setViewport(0, 0, width/2.f, height/2.f);

	Scene::renderShadows();

	frameBuffer->resize(w, h);
	frameBuffer->bindFrameBuffer();
	renderOptions->overrideShader = nullptr;
	
	Scene::render();

	renderSurface->render(frameBuffer->getTextureId());
	((VoxRenderOptions *)renderOptions)->shadowMapTextureId = 0;

	setViewport(w, 0, w, h);

	//Scene::renderShadows();

	depthBuffer->resize(w, h);
	depthBuffer->bindFrameBuffer();
	Scene::renderShadows();
	renderOptions->overrideShader = nullptr;

	Scene::render();

	renderSurface->render(depthBuffer->getTextureId());
	((VoxRenderOptions *)renderOptions)->shadowMapTextureId = 0;
	
	setViewport(w, h, w, h);

	shadowBuffer->resize(w, h);
	shadowBuffer->bindFrameBuffer();
	Scene::renderShadows();
	renderOptions->overrideShader = nullptr;

	Scene::render();

	renderSurface->render(shadowBuffer->getTextureId());
	((VoxRenderOptions *)renderOptions)->shadowMapTextureId = 0;*/

	int width, height;
	glfwGetFramebufferSize(glfwGetCurrentContext(), &width, &height);

	setViewport(0, 0, width, height);
	
	Scene::renderShadows(_matrixStack, _renderStack);
	Scene::render(_matrixStack, _renderStack);
}

void MainScene::unload(){
	frameBuffer->load();
	depthBuffer->load();
	depthShader->load();
	renderSurface->load();
	shadowSurface->load();
	shadowBuffer->load();
	baseShader->load();	
}

void MainScene::load(){
	Scene::load();
	frameBuffer->load();
	depthBuffer->load();
	depthShader->load();
	renderSurface->load();
	shadowSurface->load();
	shadowBuffer->load();
	baseShader->load();
}