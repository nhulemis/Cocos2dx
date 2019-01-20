#pragma once
#include "cocos2d.h"
#include "Model.h"
#include "Define.h"

class Explosion : public Model
{
protected:
public:
	Explosion();
	Explosion(cocos2d::Scene * scene);
	virtual ~Explosion();

	void SetPosExplotion(cocos2d::Vec2 pos);

	virtual void Update();
	virtual void Init();
};

