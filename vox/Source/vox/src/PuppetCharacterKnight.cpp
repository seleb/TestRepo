#pragma once

#include <PuppetCharacterKnight.h>
#include <PuppetTexturePack.h>
#include <BehaviourPatrol.h>
#include <BehaviourAttack.h>

#include <RaidTheCastleResourceManager.h>

#include <Item.h>

PuppetCharacterKnight::PuppetCharacterKnight(bool _ai, unsigned long int _id,  float _ghostPosition,  Box2DWorld * _world, int16 _categoryBits, int16 _maskBits, int16 _groupIndex):
	PuppetCharacter(new PuppetTexturePack(
		RaidTheCastleResourceManager::knightRedTorso,
		RaidTheCastleResourceManager::knightRedArm,
		RaidTheCastleResourceManager::knightRedHelmet
	), _ghostPosition, _ai, _world, _categoryBits, _maskBits, _groupIndex),
	NodeTransformable(new Transform()),
	NodeChild(nullptr)
{

}

PuppetCharacterKnight::~PuppetCharacterKnight(){
}