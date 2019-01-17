#pragma once
#include "cocos2d.h"
#include "Model.h"
class Rock : public Model
{
private:
	int mAmor;
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
	~Rock();
	virtual void Update();
	virtual void Init();
};

