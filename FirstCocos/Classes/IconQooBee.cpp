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

#include "IconQooBee.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* IconQooBee::createScene()
{
	//CCLOG("hello");
	auto scene = Scene::create();
	auto layer = IconQooBee::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool IconQooBee::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();

	auto qooBee = Sprite::create("qoobee.png");
	qooBee->setScale(0.5);
	qooBee->setPosition(screenSize.width / 3, screenSize.height / 3);

	addChild(qooBee);
	auto moveLeftQoobee = MoveTo::create(3, Vec2(3 * screenSize.width / 4, 3 * screenSize.height / 4));
	auto moveRightQoobee = MoveTo::create(3, Vec2(screenSize.width / 4, screenSize.height / 4));
	auto scaleUp = ScaleTo::create(1, 1.0f);
	auto scaleLow = ScaleTo::create(1, 0.5f);


	auto spawns1 = Spawn::create(moveLeftQoobee, scaleUp, nullptr);
	auto spawns2 = Spawn::create(moveRightQoobee, scaleLow, nullptr);

	auto sequence = Sequence::create(spawns1, spawns2, nullptr);

	auto repeat = RepeatForever::create(sequence);

	qooBee->runAction(repeat);
	CCLOG("qoobe");


	return true;
}



