#include "Fire.h"
#include "Define.h"
Fire::Fire(cocos2d::Scene * scenc)
{
	mSprite = cocos2d::Sprite::createWithSpriteFrameName(FIRE_DRAGON_IMG);
	mSprite->setScale(SIZE_FIRE);
	SetAlive(false);
	scenc->addChild(mSprite);
	Init();
}

Fire::~Fire()
{

}

void Fire::SetPosition(cocos2d::Vec2 pos)
{
	mSprite->setPosition(pos);
}



void Fire::Update()
{
	if (IsAlive())
	{
		auto pos = mSprite->getPosition();
		if (pos.y > SCREEN_H + mSprite->getContentSize().height/2)
		{
			SetAlive(false);
			return;
		}
		pos.y += SPEED_FIRE;
		mSprite->setPosition(pos);
	}
}

void Fire::Init()
{

}
