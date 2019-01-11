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

#include "ThirdSceneLable.h"
#include "SimpleAudioEngine.h"
#include "SecondScene.h"
#include <string>

USING_NS_CC;

Scene* ThirdSceneLable::createScene()
{
	//CCLOG("hello");
	auto scene = Scene::create();
	auto layer = ThirdSceneLable::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool ThirdSceneLable::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto _screenSize = Director::getInstance()->getVisibleSize();


	auto _thirdScene = Sprite::create("alpha.png");
	//secondScene->setScale(1.7, 1);
	_thirdScene->setPosition(_screenSize.width / 2, _screenSize.height / 2);
	addChild(_thirdScene);


	//add label
	auto _label = Label::createWithSystemFont("Wellcome to Game loft", "Arial", 25);
	_label->setColor(cocos2d::Color3B::BLUE);
	_label->setPosition(_screenSize.width / 2, _screenSize.height * 3 / 4);
	addChild(_label);

	auto printLine = [=](const std::string& mess, float X, float Y) {
		auto _showLabel = Label::createWithSystemFont(mess, "Arial", 20);
		_showLabel->setColor(cocos2d::Color3B::RED);
		_showLabel->setPosition(X, Y);
		addChild(_showLabel);

	};
	int a = 30;
	auto _callPrintMenu = [=]() {
		printLine("Play", _screenSize.width / 2, _screenSize.height * 3 / 4 - a);
		printLine("About", _screenSize.width / 2, _screenSize.height * 3 / 4 - 2 * a);
		printLine("Setting", _screenSize.width / 2, _screenSize.height * 3 / 4 - 3 * a);
		printLine("Quit", _screenSize.width / 2, _screenSize.height * 3 / 4 - 4 * a);

	};
	_callPrintMenu();


	auto _exit = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", [](Ref* ref) {
		exit(0);
	});

	_exit->setAnchorPoint(Vec2(1, 0));
	_exit->setPosition(_screenSize.width,0);

	auto _menu = Menu::create(_exit, nullptr);
	//_menu->setAnchorPoint(Vec2(1, 0));	
	_menu->setPosition(Vec2::ZERO);
	addChild(_menu,1);



	return true;
}



