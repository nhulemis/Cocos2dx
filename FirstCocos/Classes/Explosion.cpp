#include "Explosion.h"

#pragma region declare

#pragma endregion


Explosion::Explosion()
{

}

Explosion::Explosion(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create();
	SetAlive(false);
	scene->addChild(mSprite);	
}

Explosion::~Explosion()
{
}

void Explosion::SetPosExplotion(cocos2d::Vec2 pos)
{
	SetAlive(true);
	//mPos = pos;
	mSprite->setPosition(pos);
	Init();
}

void Explosion::Update()
{
	
}

void Explosion::Init()
{
	auto animate = cocos2d::Animate::create(createAnimation(EXPLOSION_IMG, 25, 0.08));
	mSprite->runAction(animate);
}
