#pragma once

#include <Box2DMeshEntity.h>

class Box2DWorld;
class Material;

class LD32_Donut : public Box2DMeshEntity{
public:
	static MeshInterface * donutTopMesh;
	static MeshInterface * donutBotMesh;
	static Material * donutMat;
	
	static MeshEntity * bot;

	LD32_Donut(Box2DWorld * _world);
	~LD32_Donut();
	
	void render(vox::MatrixStack * _matrixStack, RenderOptions * _renderOptions) override;
	void setShader(Shader * _shader, bool _def) override;
};