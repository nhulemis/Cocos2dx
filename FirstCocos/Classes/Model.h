#pragma once
#include "cocos2d.h"
class Model
{
protected:
	cocos2d::Sprite * mSprite;
	bool mAlive;
public:
	Model();
	~Model();

	void SetAlive(bool status);
	bool IsAlive();

	cocos2d::Rect GetRect();

	virtual void Update() = 0;
	virtual void Init() = 0;
};

