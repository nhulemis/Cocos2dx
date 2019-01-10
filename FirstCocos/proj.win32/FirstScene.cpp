#include "FirstScene.h"


USING_NS_CC;

cocos2d::Scene * FirstScene::CreateStartScene()
{
	auto scene = Scene::create();
	auto layer = FirstScene::create();
	scene->addChild(layer);
	return scene;
	//return nullptr;
}

bool FirstScene::Init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	auto logo = Sprite::create("splash_ground.png");
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(logo);
	return true;
}


FirstScene::FirstScene()
{
}


FirstScene::~FirstScene()
{
}
