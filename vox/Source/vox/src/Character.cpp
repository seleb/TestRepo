#pragma once

#include "Character.h"
#include "Box2DSprite.h"
#include "Box2DWorld.h"
#include "shader/Shader.h"
#include "CharacterComponent.h"
#include "Scene.h"
#include "BitmapFont.h"

#include "Texture.h"

int16 Character::gGroupIndex = 0;

ComponentTexture::ComponentTexture(Texture * _texture, float _width, float _height) :
	texture(_texture),
	width(_width),
	height(_height)
{
}

std::vector<ComponentTexture *> Character::torsoTexPacks;
std::vector<ComponentTexture *> Character::headTexPacks;
std::vector<ComponentTexture *> Character::upperArmTexPacks;
std::vector<ComponentTexture *> Character::lowerArmTexPacks;
std::vector<ComponentTexture *> Character::handTexPacks;
std::vector<ComponentTexture *> Character::upperLegTexPacks;
std::vector<ComponentTexture *> Character::lowerLegTexPacks;

void Character::init(){
	torsoTexPacks.push_back(new ComponentTexture(new Texture("../assets/MichaelTorso.png", 512, 512, true, true),	150,	360)); 
	torsoTexPacks.push_back(new ComponentTexture(new Texture("../assets/MoustacheTorso.png", 512, 512, true, true),	160,	290));
	torsoTexPacks.push_back(new ComponentTexture(new Texture("../assets/AfroTorso.png", 512, 512, true, true),		190,	325));
	torsoTexPacks.push_back(new ComponentTexture(new Texture("../assets/HoodieTorso.png", 512, 512, true, true),	175,	285));
	torsoTexPacks.push_back(new ComponentTexture(new Texture("../assets/PonytailTorso.png", 512, 512, true, true),	160,	355));

	headTexPacks.push_back(new ComponentTexture(new Texture("../assets/MichaelHead.png", 512, 512, true, true),   160,	270));
	headTexPacks.push_back(new ComponentTexture(new Texture("../assets/MoustacheHead.png", 512, 512, true, true), 160,	270));
	headTexPacks.push_back(new ComponentTexture(new Texture("../assets/AfroHead.png", 512, 512, true, true),	   260,	250));
	headTexPacks.push_back(new ComponentTexture(new Texture("../assets/HoodieHead.png", 512, 512, true, true),	   170,	300));
	headTexPacks.push_back(new ComponentTexture(new Texture("../assets/PonytailHead.png", 512, 512, true, true),  155,	365));
	headTexPacks.push_back(new ComponentTexture(new Texture("../assets/MonsterHead.png", 512, 512, true, true),  222,	393));
	
	upperArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/MichaelUpperArm.png", 512, 512, true, true),55,	205));
	upperArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/MoustacheUA.png", 512, 512, true, true),	55,	205));
	upperArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/AfroUA.png", 512, 512, true, true),			50,	200));
	upperArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/HoodieUA.png", 512, 512, true, true),		65,	165));
	upperArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/PonytailUA.png", 512, 512, true, true),		60,	200));
	
	lowerArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/MichaelLowerArm.png", 512, 512, true, true),40,	145));
	lowerArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/MoustacheLA.png", 512, 512, true, true),	40,	145));
	lowerArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/AfroLA.png", 512, 512, true, true),			40,	145));
	lowerArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/HoodieLA.png", 512, 512, true, true),		55,	165));
	lowerArmTexPacks.push_back(new ComponentTexture(new Texture("../assets/PonytailLA.png", 512, 512, true, true),		55,	160));
	
	handTexPacks.push_back(new ComponentTexture(new Texture("../assets/MichaelHand.png", 512, 512, true, true),	50,	82));
	handTexPacks.push_back(new ComponentTexture(new Texture("../assets/MoustacheHand.png", 512, 512, true, true),	55,	85));
	handTexPacks.push_back(new ComponentTexture(new Texture("../assets/AfroHand.png", 512, 512, true, true),		55,	70));
	handTexPacks.push_back(new ComponentTexture(new Texture("../assets/HoodieHand.png", 512, 512, true, true),		55,	85));
	handTexPacks.push_back(new ComponentTexture(new Texture("../assets/PonytailHand.png", 512, 512, true, true),	60,	80));
	
	upperLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/MichaelUpperLeg.png", 512, 512, true, true), 70,	215));
	upperLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/MoustacheUL.png", 512, 512, true, true),	 70,	215));
	upperLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/AfroUL.png", 512, 512, true, true),			 60,	200));
	upperLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/HoodieUL.png", 512, 512, true, true),		 50,	205));
	upperLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/PonytailUL.png", 512, 512, true, true),		 80,	185));
	
	lowerLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/MichaelLowerLeg.png", 512, 512, true, true), 135,	285));
	lowerLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/MoustacheLL.png", 512, 512, true, true),	 135,	285));
	lowerLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/AfroLL.png", 512, 512, true, true),			 105,	255));
	lowerLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/HoodieLL.png", 512, 512, true, true),		 115,	240));
	lowerLegTexPacks.push_back(new ComponentTexture(new Texture("../assets/PonytailLL.png", 512, 512, true, true),		 110,	205));
}

Character::Character(Box2DWorld * _world, bool _ai) :
	MeshEntity(nullptr, new Transform()),
	NodeTransformable(new Transform()),
	NodeChild(nullptr),
	world(_world),
	componentScale(0.0025f),
	groupIndex(--gGroupIndex),
	ai(_ai),
	text(new BitmapFont(new Texture("../assets/arial.bmp", 1024, 1024, true, true), 32, 16, 16 )),
	reactiveFeet(true),
	head(nullptr),
	leftUpperArm(nullptr),
	leftLowerArm(nullptr),
	leftHand(nullptr),
	rightUpperArm(nullptr),
	rightLowerArm(nullptr),
	rightHand(nullptr),
	leftUpperLeg(nullptr),
	leftLowerLeg(nullptr),
	rightUpperLeg(nullptr),
	rightLowerLeg(nullptr)

{
	ratioX_neck_to_torso = 0.0f;
	ratioY_neck_to_torso = 0.8f;
	ratioX_torso_to_neck = 0.0f;
	ratioY_torso_to_neck = 0.8f;
	
	ratioX_shoulder_to_torso = 0.f;
	ratioY_shoulder_to_torso = 1.f;
	ratioX_torso_to_shoulder = 0.8f;
	ratioY_torso_to_shoulder = 0.5f;
	
	ratioX_elbow_to_shoulder = 0.f;
	ratioY_elbow_to_shoulder = 0.7f;
	ratioX_shoulder_to_elbow = 0.f;
	ratioY_shoulder_to_elbow = 0.7f;
	
	ratioX_wrist_to_elbow = 0.f;
	ratioY_wrist_to_elbow = 0.8f;
	ratioX_elbow_to_wrist = 0.f;
	ratioY_elbow_to_wrist = 0.8f;
	
	ratioX_hip_to_torso = 0.f;
	ratioY_hip_to_torso = 1.f;
	ratioX_torso_to_hip = 0.55f;
	ratioY_torso_to_hip = 0.7f;
	
	ratioX_knee_to_hip = 1.0f;
	ratioY_knee_to_hip = 0.8f;
	ratioX_hip_to_knee = 1.0f;
	ratioY_hip_to_knee = 0.8f;

	text->transform->translate(0, 0, 6);
	text->kerning = 0.75f;
	text->setSizeMod(0.85f);

	components.push_back(head);
	components.push_back(leftUpperArm);
	components.push_back(leftLowerArm);
	components.push_back(leftHand);
	components.push_back(rightUpperArm);
	components.push_back(rightLowerArm);
	components.push_back(rightHand);
	components.push_back(leftUpperLeg);
	components.push_back(leftLowerLeg);
	components.push_back(rightUpperLeg);
	components.push_back(rightLowerLeg);

}

Character::~Character(){
	while(components.size() > 0){
		delete components.back();
	}
	components.clear();
}

void Character::render(vox::MatrixStack * _matrixStack, RenderOptions * _renderStack){
	MeshEntity::render(_matrixStack, _renderStack);
}

void Character::update(Step * _step){
	MeshEntity::update(_step);
	if(reactiveFeet){
		b2RevoluteJoint * neck = ((b2RevoluteJoint *)head->body->GetJointList()->joint);
		float angle = neck->GetJointAngle();

		neck->SetMotorSpeed(-angle*360);
		neck->SetMaxMotorTorque(head->body->GetMass()*750*(std::abs(angle)*5));

		float bodAngle = torso->body->GetAngle();
		torso->body->SetAngularVelocity(-bodAngle*10);
		if(torso->body->GetPosition().y < 5){
			torso->applyLinearImpulseUp(250);
		}
	}
	
	/*if(angle < neck->GetLowerLimit()/2 || angle > neck->GetUpperLimit()/2){
		neck->SetMotorSpeed(angle < 0 ? 0.1 : -0.1);
		neck->SetMaxMotorTorque(head->body->GetMass()*1000);
	}else{
		neck->SetMotorSpeed(0);
		neck->SetMaxMotorTorque(0);
	}*/

	if(ai && reactiveFeet){
		b2ContactEdge * stuff = leftLowerLeg->body->GetContactList();
		if(stuff != nullptr && stuff->contact->IsTouching()){
			int type1 = (int)stuff->contact->GetFixtureA()->GetUserData();
			int type2 = (int)stuff->contact->GetFixtureB()->GetUserData();

			if(type1 != type2){
				if(leftLowerLeg->body->GetLinearVelocity().y <= 0.1){
					leftLowerLeg->applyLinearImpulseUp(125);	
					torso->applyLinearImpulseUp(125);	
				}
			}
		}
		stuff = rightLowerLeg->body->GetContactList();
		if(stuff != nullptr && stuff->contact->IsTouching()){
			int type1 = (int)stuff->contact->GetFixtureA()->GetUserData();
			int type2 = (int)stuff->contact->GetFixtureB()->GetUserData();

			if(type1 != type2){
				if(rightLowerLeg->body->GetLinearVelocity().y <= 0.1){
					rightLowerLeg->applyLinearImpulseUp(125);
					torso->applyLinearImpulseUp(125);	
				}
			}
		}
	}
	text->transform->translationVector.x = (torso->transform->translationVector.x) - text->getWidth()/4;
	text->transform->translationVector.y = head->transform->translationVector.y + 1.5f;
}

void Character::attachJoints(){

	/*for(NodeChild * s : children){
		dynamic_cast<Box2DSprite *>(s)->transform->scale(5,5,1);
	}*/

	torso->createFixture(groupIndex);
	head->createFixture(groupIndex);

	
	float correctedTorsoWidth = torso->getCorrectedWidth();
	float correctedTorsoHeight = torso->getCorrectedHeight();

	// neck
	b2RevoluteJointDef jth;
	jth.bodyA = torso->body;
	jth.bodyB = head->body;
	jth.localAnchorA.Set(ratioX_torso_to_neck * correctedTorsoWidth, ratioY_torso_to_neck * correctedTorsoHeight);
	jth.localAnchorB.Set(ratioX_neck_to_torso * head->getCorrectedWidth(), ratioY_neck_to_torso * -head->getCorrectedHeight());
	jth.collideConnected = false;
	jth.enableLimit = true;
	jth.enableMotor = true;
	jth.maxMotorTorque = 0;
	jth.motorSpeed = 0;
	jth.referenceAngle = 0;
	jth.lowerAngle = -glm::radians(45.f);
	jth.upperAngle = glm::radians(45.f);
	world->b2world->CreateJoint(&jth);

	// left shoulder
	leftUpperArm->createFixture(groupIndex);
	b2RevoluteJointDef latj;
	latj.bodyA = torso->body;
	latj.bodyB = leftUpperArm->body;
	latj.localAnchorA.Set(-ratioX_torso_to_shoulder * correctedTorsoWidth, ratioY_torso_to_shoulder * correctedTorsoHeight);
	latj.localAnchorB.Set(ratioX_shoulder_to_torso * leftUpperArm->getCorrectedWidth(), ratioY_shoulder_to_torso * leftUpperArm->getCorrectedHeight());
	latj.collideConnected = false;
	latj.enableLimit = true;
	latj.referenceAngle = glm::radians(0.f);
	latj.lowerAngle = glm::radians(-120.f);
	latj.upperAngle = glm::radians(10.f);
	world->b2world->CreateJoint(&latj);
	

	// right shoulder
	rightUpperArm->createFixture(groupIndex);
	b2RevoluteJointDef ratj;
	ratj.bodyA = torso->body;
	ratj.bodyB = rightUpperArm->body;
	ratj.localAnchorA.Set(ratioX_torso_to_shoulder * correctedTorsoWidth, ratioY_torso_to_shoulder * correctedTorsoHeight);
	ratj.localAnchorB.Set(ratioX_shoulder_to_torso * leftUpperArm->getCorrectedWidth(), ratioY_shoulder_to_torso * leftUpperArm->getCorrectedHeight());
	ratj.collideConnected = false;
	ratj.enableLimit = true;
	ratj.referenceAngle = glm::radians(0.f);
	ratj.lowerAngle = glm::radians(-10.f);
	ratj.upperAngle = glm::radians(120.f);
	world->b2world->CreateJoint(&ratj);
	
	
	// left elbow
	leftLowerArm->createFixture(groupIndex);
	b2RevoluteJointDef lelsj;
	lelsj.bodyA = leftUpperArm->body;
	lelsj.bodyB = leftLowerArm->body;
	lelsj.localAnchorA.Set(-ratioX_shoulder_to_elbow * leftUpperArm->getCorrectedWidth(), -ratioY_shoulder_to_elbow * leftUpperArm->getCorrectedHeight());
	lelsj.localAnchorB.Set(-ratioX_elbow_to_shoulder * leftLowerArm->getCorrectedWidth(), ratioY_elbow_to_shoulder * leftLowerArm->getCorrectedHeight());
	lelsj.collideConnected = false;
	lelsj.enableLimit = true;
	lelsj.referenceAngle = glm::radians(0.f);
	lelsj.lowerAngle = glm::radians(-10.f);
	lelsj.upperAngle = glm::radians(90.f);
	world->b2world->CreateJoint(&lelsj);

	// right elbow
	rightLowerArm->createFixture(groupIndex);
	b2RevoluteJointDef rersj;
	rersj.bodyA = rightUpperArm->body;
	rersj.bodyB = rightLowerArm->body;
	rersj.localAnchorA.Set(-ratioX_shoulder_to_elbow * rightUpperArm->getCorrectedWidth(), -ratioY_shoulder_to_elbow * rightUpperArm->getCorrectedHeight());
	rersj.localAnchorB.Set(ratioX_elbow_to_shoulder * rightLowerArm->getCorrectedWidth(), ratioY_elbow_to_shoulder * rightLowerArm->getCorrectedHeight());
	rersj.collideConnected = false;
	rersj.enableLimit = true;
	rersj.referenceAngle = glm::radians(0.f);
	rersj.lowerAngle = glm::radians(-90.f);
	rersj.upperAngle = glm::radians(10.f);
	world->b2world->CreateJoint(&rersj);

	// left hand
	leftHand->createFixture(groupIndex);
	b2RevoluteJointDef lhlej;
	lhlej.bodyA = leftLowerArm->body;
	lhlej.bodyB = leftHand->body;
	lhlej.localAnchorA.Set(-ratioX_elbow_to_wrist * leftLowerArm->getCorrectedWidth(), -ratioY_elbow_to_wrist * leftLowerArm->getCorrectedHeight());
	lhlej.localAnchorB.Set(-ratioX_wrist_to_elbow * leftHand->getCorrectedWidth(), ratioY_wrist_to_elbow * leftHand->getCorrectedHeight());
	lhlej.collideConnected = false;
	lhlej.enableLimit = true;
	lhlej.referenceAngle = glm::radians(0.f);
	lhlej.lowerAngle = glm::radians(-20.f);
	lhlej.upperAngle = glm::radians(20.f);
	world->b2world->CreateJoint(&lhlej);

	// right hand
	rightHand->createFixture(groupIndex);
	b2RevoluteJointDef rhrej;
	rhrej.bodyA = rightLowerArm->body;
	rhrej.bodyB = rightHand->body;
	rhrej.localAnchorA.Set(-ratioX_elbow_to_wrist * rightLowerArm->getCorrectedWidth(), -ratioY_elbow_to_wrist * rightLowerArm->getCorrectedHeight());
	rhrej.localAnchorB.Set(ratioX_wrist_to_elbow * rightHand->getCorrectedWidth(), ratioY_wrist_to_elbow * rightHand->getCorrectedHeight());
	rhrej.collideConnected = false;
	rhrej.enableLimit = true;
	rhrej.referenceAngle = glm::radians(0.f);
	rhrej.lowerAngle = glm::radians(-20.f);
	rhrej.upperAngle = glm::radians(20.f);
	world->b2world->CreateJoint(&rhrej);

	// left hip
	leftUpperLeg->createFixture(groupIndex);
	b2RevoluteJointDef lltj;
	lltj.bodyA = torso->body;
	lltj.bodyB = leftUpperLeg->body;
	lltj.localAnchorA.Set(-ratioX_torso_to_hip * correctedTorsoWidth, -ratioY_torso_to_hip * correctedTorsoHeight);
	lltj.localAnchorB.Set(ratioX_hip_to_torso * leftUpperLeg->getCorrectedWidth(),  ratioY_hip_to_torso * leftUpperLeg->getCorrectedHeight());
	lltj.collideConnected = false;
	lltj.enableLimit = true;
	lltj.lowerAngle = glm::radians(-100.f);
	lltj.upperAngle = glm::radians(25.f);
	world->b2world->CreateJoint(&lltj);
	
	// right hip
	rightUpperLeg->createFixture(groupIndex);
	b2RevoluteJointDef lrtj;
	lrtj.bodyA = torso->body;
	lrtj.bodyB = rightUpperLeg->body;
	lrtj.localAnchorA.Set(ratioX_torso_to_hip * correctedTorsoWidth, -ratioY_torso_to_hip * correctedTorsoHeight);
	lrtj.localAnchorB.Set(ratioX_hip_to_torso * leftUpperLeg->getCorrectedWidth(), ratioY_hip_to_torso * rightUpperLeg->getCorrectedHeight());
	lrtj.collideConnected = false;
	lrtj.enableLimit = true;
	lrtj.lowerAngle = glm::radians(-25.f);
	lrtj.upperAngle = glm::radians(100.f);
	world->b2world->CreateJoint(&lrtj);

	// left knee
	leftLowerLeg->createFixture(groupIndex);
	b2RevoluteJointDef llltj;
	llltj.bodyA = leftUpperLeg->body;
	llltj.bodyB = leftLowerLeg->body;
	llltj.localAnchorA.Set(ratioX_hip_to_knee * leftUpperLeg->getCorrectedWidth(), -ratioY_hip_to_knee * leftUpperLeg->getCorrectedHeight());
	llltj.localAnchorB.Set(ratioX_knee_to_hip * leftLowerLeg->getCorrectedWidth(), ratioY_knee_to_hip * leftLowerLeg->getCorrectedHeight());
	llltj.collideConnected = false;
	llltj.enableLimit = true;
	llltj.lowerAngle = glm::radians(0.f);
	llltj.upperAngle = glm::radians(75.f);
	world->b2world->CreateJoint(&llltj);
	
	// right knee
	rightLowerLeg->createFixture(groupIndex);
	b2RevoluteJointDef lrltj;
	lrltj.bodyA = rightUpperLeg->body;
	lrltj.bodyB = rightLowerLeg->body;
	lrltj.localAnchorA.Set(-ratioX_hip_to_knee * rightUpperLeg->getCorrectedWidth(), -ratioY_hip_to_knee * rightUpperLeg->getCorrectedHeight());
	lrltj.localAnchorB.Set(-ratioX_knee_to_hip * rightLowerLeg->getCorrectedWidth(), ratioY_knee_to_hip * rightLowerLeg->getCorrectedHeight());
	lrltj.collideConnected = false;
	lrltj.enableLimit = true;
	lrltj.lowerAngle = glm::radians(-75.f);
	lrltj.upperAngle = glm::radians(0.f);
	world->b2world->CreateJoint(&lrltj);

	
	float t = groupIndex*0.000001f;

	torso		   ->setTranslationPhysical(0.f, 0.f, 0.1f+t);
	head		   ->setTranslationPhysical(0.f, 0.f, 0.2f+t);
	leftUpperArm   ->setTranslationPhysical(0.f, 0.f, 0.31f+t);
	leftLowerArm   ->setTranslationPhysical(0.f, 0.f, 0.32f+t);
	leftHand	   ->setTranslationPhysical(0.f, 0.f, 0.33f+t);
	rightUpperArm  ->setTranslationPhysical(0.f, 0.f, -0.11f+t);
	rightLowerArm  ->setTranslationPhysical(0.f, 0.f, -0.12f+t);
	rightHand	   ->setTranslationPhysical(0.f, 0.f, -0.13f+t);
	leftUpperLeg   ->setTranslationPhysical(0.f, 0.f, -0.21f+t);
	leftLowerLeg   ->setTranslationPhysical(0.f, 0.f, -0.22f+t);
	rightUpperLeg  ->setTranslationPhysical(0.f, 0.f, -0.23f+t);
	rightLowerLeg  ->setTranslationPhysical(0.f, 0.f, -0.24f+t);

	torso->body->SetLinearDamping(0.9);
	torso->body->SetGravityScale(0.5);
}

void Character::unload(){
}

void Character::load(){
}

void Character::setShader(Shader * _shader){
	torso	      ->setShader(_shader, true);
	head		  ->setShader(_shader, true);
	leftUpperArm  ->setShader(_shader, true);
	leftLowerArm  ->setShader(_shader, true);
	leftHand	  ->setShader(_shader, true);
	rightUpperArm ->setShader(_shader, true);
	rightLowerArm ->setShader(_shader, true);
	rightHand	  ->setShader(_shader, true);
	leftUpperLeg  ->setShader(_shader, true);
	leftLowerLeg  ->setShader(_shader, true);
	rightUpperLeg ->setShader(_shader, true);
	rightLowerLeg ->setShader(_shader, true);
	text->setShader(_shader ,true);
}

void Character::addToScene(Scene * _scene){
	_scene->addChild(torso);
	_scene->addChild(leftUpperArm);
	_scene->addChild(leftLowerArm);
	_scene->addChild(leftHand);
	_scene->addChild(rightUpperArm);
	_scene->addChild(rightLowerArm);
	_scene->addChild(rightHand);
	_scene->addChild(leftUpperLeg);
	_scene->addChild(leftLowerLeg);
	_scene->addChild(rightUpperLeg);
	_scene->addChild(rightLowerLeg);
	_scene->addChild(head);
	_scene->addChild(text);
}

void Character::translateComponents(glm::vec3 _translateVector){
	for(CharacterComponent * c : components){
		if(c != nullptr){
			c->setTranslationPhysical(_translateVector, true);
		}
	}
}