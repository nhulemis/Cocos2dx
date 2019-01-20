

#include "StartScene.h"
#include "GameScene.h"
#include "Define.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* StartScene::createScene()
{
	return StartScene::create();
}

#pragma region declare
//CocosDenshion::SimpleAudioEngine* soundBackGround;
#pragma endregion


bool StartScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites.plist", "sprites.png");

	auto backGround = cocos2d::Sprite::create(BACKGROUND_IMG);
	backGround->setScale(0.8);
	backGround->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(backGround);


	//soundBackGround = CocosDenshion::SimpleAudioEngine::getInstance();
	//soundBackGround->playBackgroundMusic(SOUND_BACKGROUND, true);
	////soundBackGround->playEffect(SOUND_EFFECT, false, 1, 1, 1);


	auto _lblPlay = cocos2d::Label::createWithTTF("PLAY",FONT_GAME,40);
	_lblPlay->setColor(cocos2d::Color3B::WHITE);
	auto _play = cocos2d::MenuItemFont::create("PLAY", [=](Ref* sender) {
		Director::getInstance()->replaceScene(TransitionFadeDown::create(1, GameScene::createScene()));
	});
	_play->setColor(cocos2d::Color3B::WHITE);
	_play->setPosition(SCREEN_W / 2, SCREEN_H / 2);

	auto _lblExit = cocos2d::Label::createWithTTF( "EXIT", FONT_GAME, 30);
	_lblExit->setColor(cocos2d::Color3B::WHITE);
	auto _exit = cocos2d::MenuItemFont::create("EXIT", [=](Ref * sender) {
		log("xyz");
	});
	_exit->setColor(cocos2d::Color3B::WHITE);
	_exit->setPosition(SCREEN_W / 2, SCREEN_H / 3);

	auto _menu = cocos2d::Menu::create(_play, _exit,nullptr);
	_menu->setAnchorPoint(Vec2(0,0));
	_menu->setPosition(0, 0);

	this->addChild(_menu, 999);
	return true;
}
