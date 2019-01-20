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

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Rock.h"
#include "Define.h"
#include <vector>
#include "KnightSky.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance

#pragma region declare
std::vector<Rock*> rocks;
int mFrameCount = 0;
CocosDenshion::SimpleAudioEngine *soundBackGround;
KnightSky *k;


#pragma endregion


bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	std::srand(time(0));

	//Common::Score = 0;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites.plist", "sprites.png");

	auto backGround = cocos2d::Sprite::create(BACKGROUND_IMG);
	backGround->setScale(0.8);
	backGround->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(backGround);


	soundBackGround = CocosDenshion::SimpleAudioEngine::getInstance();
	soundBackGround->playBackgroundMusic(SOUND_BACKGROUND, true);
	//soundBackGround->playEffect(SOUND_EFFECT, false, 1, 1, 1);



	for (int i = 0; i < MAX_ROCK_ON_SCREEN; i++)
	{
		rocks.push_back(new Rock(this));
	}

	k = new KnightSky(this);

	

	scheduleUpdate();
	return true;
}

void GameScene::RockFall()
{
	for (int i = 0; i < rocks.size(); i++)
	{
		if (!rocks.at(i)->IsAlive())
		{
			rocks.at(i)->SetAlive(true);
			rocks.at(i)->Init();
			break;
		}
	}
}

void GameScene::update(float delta)
{
	
	mFrameCount++;
	if (mFrameCount % 3 == 0)
	{
		RockFall();
	}

	k->Update();
	k->Collision(rocks,this);

	for (int i = 0; i < rocks.size(); i++)
	{
		rocks.at(i)->Update();
	}

	if (!k->IsAlive())
	{
		cocos2d::Director::getInstance()->pause();
		soundBackGround->pauseBackgroundMusic();
		MemoryLeak();
	}

}

void GameScene::MemoryLeak()
{
	for each (auto var in rocks)
	{
		delete var;
	}
	delete k;	
}
