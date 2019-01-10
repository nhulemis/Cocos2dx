#include "FirstScene.h"

USING_NS_CC;

cocos2d::Scene * FirstScene::CreateBackGround()
{
	auto scene = Scene::create();
	auto layer = FirstScene::create();
	scene->addChild(layer);
	return scene;
}

bool FirstScene::Init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto size = Director::getInstance()->getVisibleSize();
	auto imageBackGround = Sprite::create("background1");
	imageBackGround->setPosition(size);
	addChild(imageBackGround);
	return true;
	
}

FirstScene::FirstScene()
{


}


FirstScene::~FirstScene()
{
}
