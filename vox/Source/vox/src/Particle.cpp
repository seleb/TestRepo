#pragma once

#include <Particle.h>
#include <Box2DSuperSprite.h>

Particle::Particle(Box2DWorld * _world, TextureSampler * _texture, Transform * _transform) :
Box2DSprite(_world, b2_dynamicBody, false, nullptr, _transform, _texture->width, _texture->height, _texture->texture),
NodeTransformable(_transform),
NodeChild(nullptr),
life(1),
age(0),
alive(true)
{
	b2Filter f;
	f.categoryBits = 0;
	f.groupIndex = 0;
	f.maskBits = 0;
    createFixture(f, b2Vec2(0,0), this);
}
void Particle::update(Step * _step){
    Box2DSprite::update(_step);
    age += _step->deltaTime;
    if (age > life){
        alive = false;
	}else{
		transform->scaleVector.x = 1.f - age / life;
		transform->scaleVector.y = 1.f - age / life;
	}
}

Particle::~Particle(){

}