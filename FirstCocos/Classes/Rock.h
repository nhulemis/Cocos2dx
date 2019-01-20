#pragma once
#include "cocos2d.h"
#include "Model.h"
class Rock : public Model
{
private:
	int mArmor;
	float mSize;
	float mCurX;
	float mCurY;
	float mMarkX;
	float mMarkY;
	int mStep;
	float mTiltA;
	float mTiltB;
	float mRotate;

public:
	Rock(cocos2d::Scene* scenc);
	virtual ~Rock();

	cocos2d::Vec2 GetPosition();
	cocos2d::Animation * createAnimation(std::string name, int frames, float delay);

	int GetArmor();

	virtual void Update();
	virtual void Init();
};

