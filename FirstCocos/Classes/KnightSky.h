#pragma once
#include "cocos2d.h"
#include "Model.h"
#include "Rock.h"
#include <vector>

class KnightSky : public Model
{
private:
	
public:
	KnightSky(cocos2d::Scene* scenc);
	~KnightSky();
	virtual void Update();
	virtual void Init();
	cocos2d::Animation * createAnimation(std::string name, int frames, float delay);

	void Fight();

	void Collision(std::vector<Rock*> rocks);

	virtual bool OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* evt);
	virtual void OnTouchMoved(cocos2d::Touch* touch, cocos2d::Event* evt);
	virtual void OnTouchEnded(cocos2d::Touch* touch, cocos2d::Event* evt);
};

