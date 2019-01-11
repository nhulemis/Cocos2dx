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
#include <ui\CocosGUI.h>

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


	auto _thirdScene = Sprite::create("splash_back.png");
	//secondScene->setScale(1.7, 1);
	_thirdScene->setPosition(_screenSize.width / 2, _screenSize.height / 2);
	addChild(_thirdScene);


	//add label custom font 
	int a = 50;
	auto _label = Label::createWithTTF("Wellcome to Gameloft", "fonts/vtks distress.ttf", 45);
	_label->setColor(cocos2d::Color3B::WHITE);
	_label->setPosition(_screenSize.width / 2, _screenSize.height * 3 / 4 + a);
	addChild(_label);

	auto printLabel = [](const std::string& mess)->Label* {
		auto lblItem =  Label::createWithTTF("Wellcome to Gameloft", "fonts/File.ttf", 35);
		return lblItem;
	};

	auto _callPrintMenu = [=]() {
		auto _itemPlay = MenuItemFont::create("play", nullptr);
		auto _itemAbout = MenuItemFont::create("About", nullptr);
		auto _itemSetting = MenuItemFont::create("Setting", nullptr);
		auto _itemQuit = MenuItemFont::create("Quit", nullptr);

		_itemPlay->setColor(cocos2d::Color3B::WHITE);
		_itemAbout->setColor(cocos2d::Color3B::WHITE);
		_itemSetting->setColor(cocos2d::Color3B::WHITE);
		_itemQuit->setColor(cocos2d::Color3B::WHITE);


		_itemPlay->setPosition(_screenSize.width / 2, _screenSize.height * 3 / 4 - a);
		_itemAbout->setPosition(_screenSize.width / 2, _screenSize.height * 3 / 4 - 2 * a);
		_itemSetting->setPosition(_screenSize.width / 2, _screenSize.height * 3 / 4 - 3 * a);
		_itemQuit->setPosition(_screenSize.width / 2, _screenSize.height * 3 / 4 - 4 * a);

		auto _exit = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", [](Ref* ref) {
			exit(0);
		});

		_exit->setAnchorPoint(Vec2(1, 0));
		_exit->setPosition(_screenSize.width, 0);

		auto _menu = Menu::create(_exit,_itemPlay,_itemAbout,_itemSetting,_itemQuit, nullptr);
		//_menu->setAnchorPoint(Vec2(1, 0));	
		_menu->setPosition(Vec2::ZERO);
		addChild(_menu, 1);
	};

	_callPrintMenu();

	static auto _checkbox = ui::CheckBox::create("checkbox_normal.png",
		"checkbox_pressed.png", "checkbox_checked.png",
		"checkbox_normal_disable.png", "checkbox_checked_disable.png");
	_checkbox->setSelected(true);
	_checkbox->addClickEventListener([&](Ref* event) {
		log("CheckBox state: %d", _checkbox->isSelected());
		//_checkbox->setSelected(false);
	});
	_checkbox->setPosition(Vec2(100, 100));
	_checkbox->setEnabled(true);
	addChild(_checkbox);


	return true;
}



