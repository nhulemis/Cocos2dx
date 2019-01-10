#pragma once
#include <cocos2d.h>
class FirstScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* CreateBackGround();

	virtual bool Init();

	CREATE_FUNC(FirstScene);

	FirstScene();
	~FirstScene();
};

