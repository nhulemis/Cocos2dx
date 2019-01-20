#pragma once
#include "cocos2d.h"
class Model
{
protected:
	cocos2d::Sprite * mSprite;
	bool mAlive;
public:
	Model();
	virtual ~Model();

	virtual void SetAlive(bool status);
	bool IsAlive();

	cocos2d::Rect GetRect();
	virtual cocos2d::Animation * createAnimation(std::string name, int frames, float delay);
	virtual void Update() = 0;
	virtual void Init() = 0;
};

