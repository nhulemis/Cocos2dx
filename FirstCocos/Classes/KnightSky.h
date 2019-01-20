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
	virtual ~KnightSky();
	virtual void Update();
	virtual void Init();
	
	virtual void SetAlive(bool status) override;
	void Fight();

	void Collision(std::vector<Rock*> rocks, cocos2d::Scene * scene);
//	void Explosion(cocos2d::Scene * scene,cocos2d::Vec2 pos);

	virtual bool OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* evt);
	virtual void OnTouchMoved(cocos2d::Touch* touch, cocos2d::Event* evt);
	virtual void OnTouchEnded(cocos2d::Touch* touch, cocos2d::Event* evt);
};

