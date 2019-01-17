#include "Rock.h"
#include "Define.h"
Rock::Rock(cocos2d::Scene * scenc)
{
	mSprite = cocos2d::Sprite::createWithSpriteFrameName(ROCK_IMG_1);
	SetAlive(false);
	scenc->addChild(mSprite);
	Init();
}

Rock::~Rock()
{
}

void Rock::Update()
{
	if (IsAlive())
	{
		auto pos = mSprite->getPosition();
		if (pos.y < -50)
		{
			SetAlive(false);
			return;
		}
		pos.y -= mStep;
		pos.x = (float)(pos.y - mTiltB) / mTiltA;
		mSprite->setPosition(pos);
	}
}

void Rock::Init()
{
	//
	auto x = cocos2d::random(- OVER_, SCREEN_W+ OVER_);
	mCurX = x;
	mCurY = SCREEN_H + mSprite->getContentSize().height / 2;
	mSprite->setPosition(cocos2d::Vec2(mCurX, mCurY));
	//
	x = cocos2d::random(-OVER_, SCREEN_W + OVER_);
	mMarkX = x;
	mMarkY = -mSprite->getContentSize().height / 2;

	//
	mSize =(float) cocos2d::random(SIZE_ROCK_MIN, SIZE_ROCK_MAX)/10;
	mSprite->setScale(mSize);
	//
	mStep = cocos2d::random(ROCK_STEP_MIN, ROCK_STEP_MAX);

	//
	mTiltA = (float)(800 + 50) / (this->mCurX - this->mMarkX);
	mTiltB = (float) this->mCurY - this->mTiltA * this->mCurX;

	//
	mRotate = cocos2d::random(ROTATE_MIN, ROTATE_MAX);
	auto rotate = cocos2d::RotateTo::create(mStep, mRotate);
	mSprite->runAction(rotate);

	//


}
