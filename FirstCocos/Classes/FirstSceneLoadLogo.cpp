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

#include "FirstSceneLoadLogo.h"
#include "SimpleAudioEngine.h"
#include "SecondScene.h"

USING_NS_CC;

Scene* FirstSceneLoadLogo::createScene()
{
	CCLOG("createScene");
	auto scene = Scene::create();
	auto layer = FirstSceneLoadLogo::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool FirstSceneLoadLogo::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	auto screenSize = Director::getInstance()->getVisibleSize();
	auto secondScene = Sprite::create("thephone.png");

	secondScene->setScale(0.4);
	secondScene->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(secondScene);
	CCLOG("init");

	auto _listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = [](Touch *touch, Event *event) {

		CCLOG("touch");

		auto gotoNext = SecondScene::createScene();
		Director::getInstance()->replaceScene(gotoNext);
		return true;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
    return true;
}





