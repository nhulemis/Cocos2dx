#pragma once
#include "cocos2d.h"
#include "Model.h"
class Fire : public Model
{
private:
	
public:
	Fire(cocos2d::Scene* scenc);
	~Fire();
	void SetPosition(cocos2d::Vec2 pos);
	virtual void Update();
	virtual void Init();
};

