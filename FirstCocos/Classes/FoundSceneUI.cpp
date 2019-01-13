/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "FoundSceneUI.h"
#include "SimpleAudioEngine.h"
#include "SecondScene.h"
#include <string>
#include <vector>
#include <ui\CocosGUI.h>

USING_NS_CC;

Scene* FourSceneUI::createScene()
{
	//CCLOG("hello");
	auto scene = Scene::create();
	auto layer = FourSceneUI::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool FourSceneUI::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	auto _backGround = Sprite::create("nightSky.png");

	auto _screenSize = Director::getInstance()->getVisibleSize();

	_backGround->setPosition(_screenSize.width / 2, _screenSize.height / 2);

	addChild(_backGround);


	//static auto _checkbox = ui::CheckBox::create("checkbox_normal.png",
	//	"checkbox_pressed.png", "checkbox_checked.png",
	//	"checkbox_normal_disable.png", "checkbox_checked_disable.png");
	//_checkbox->setSelected(true);
	//_checkbox->addClickEventListener([&](Ref* event) {
	//	log("CheckBox state: %d", _checkbox->isSelected());
	//	//_checkbox->setSelected(false);
	//});
	//_checkbox->setScale(0.5);
	//_checkbox->setPosition(Vec2(100, 100));
	//_checkbox->setEnabled(true);
	//addChild(_checkbox);

	//cac node luu tru hinh anh 
	auto *spriteNode = SpriteBatchNode::create("the boy/sprites.png");

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("the boy/sprites.plist");

	_phase1 = Sprite::createWithSpriteFrameName("Capture_01.png");

	_phase1->setPosition(_screenSize.width / 3, _screenSize.height / 3);

	spriteNode->addChild(_phase1);

	this->addChild(spriteNode);

	auto animate = Animate::create(FourSceneUI::CreateAnimate("Capture_",8,0.15));
	animate->retain();
	_phase1->runAction(RepeatForever::create(animate));

	auto _listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = CC_CALLBACK_2(FourSceneUI::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
	return true;
}


bool FourSceneUI::OnTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	animation->release();
	animation = FourSceneUI::CreateAnimate("Capture_runleft_", 8, 0.15);
	auto animate = Animate::create(animation);
	animate->retain();
	_phase1->runAction(RepeatForever::create(animate));
	return true;
}

Animation * FourSceneUI::CreateAnimate(std::string name, int totalFrame, float delay)
{
	cocos2d::Vector<SpriteFrame*> animateFrames;
	for (int i = 1; i <= totalFrame; i++)
	{
		char buffer[20] = { 0 };
		if (i<10)
		{
			sprintf(buffer, "0%d.png", i);
		}
		else
		{
			sprintf(buffer, "%d.png", i);
		}
		std::string _name = name + buffer;
		auto _frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(_name);
		animateFrames.pushBack(_frame);
	}

	animation =  Animation::createWithSpriteFrames(animateFrames,delay);

	return animation;
}



