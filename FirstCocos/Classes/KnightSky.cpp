#include "KnightSky.h"
#include "Define.h"
#include "fire.h"
#include "cpVect.h"

#pragma region declare
std::vector<Fire*> fires;

int frameCount = 0;

bool controlKnight = false;
cocos2d::Vec2 distanceTouchToDragon;

#pragma endregion


KnightSky::KnightSky(cocos2d::Scene * scene)
{
	mSprite = cocos2d::Sprite::create();
	SetAlive(true);
	auto animation = createAnimation(DRAGON_KNIGHT, 4, 0.15);
	auto sequence = cocos2d::Sequence::create(cocos2d::Animate::create(animation),
		nullptr
	);
	mSprite->runAction(cocos2d::RepeatForever::create(sequence));
	mSprite->setPosition(SCREEN_W / 2, SCREEN_H / 10);
	mSprite->setScale(1.2);
	scene->addChild(mSprite);

	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(KnightSky::OnTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(KnightSky::OnTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(KnightSky::OnTouchEnded, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, scene);

	for (int i = 0; i < 20; i++)
	{
		fires.push_back(new Fire(scene));
	}


	Init();
}

KnightSky::~KnightSky()
{

}

void KnightSky::Update()
{
	frameCount++;
	if (frameCount % 4 == 0)
	{
		Fight();
	}

	for (int i = 0; i < fires.size(); i++)
	{
		fires.at(i)->Update();
	}
}

void KnightSky::Init()
{
}


cocos2d::Animation * KnightSky::createAnimation(std::string name, int frames, float delay)
{
	cocos2d::Vector<cocos2d::SpriteFrame*> _frames;
	for (int i = 1; i <= frames; i++)
	{
		char buffer[20] = { 0 };
		sprintf(buffer, "(%d).png", i);
		std::string _name = name + buffer;
		auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(_name);
		_frames.pushBack(frame);
	}
	auto anima = cocos2d::Animation::createWithSpriteFrames(_frames, delay);
	return anima;
}

void KnightSky::Fight()
{
	for (int i = 0; i < fires.size(); i++)
	{
		if (!fires.at(i)->IsAlive())
		{
			fires.at(i)->SetAlive(true);
			auto pos = mSprite->getPosition();
			auto cur = mSprite->getContentSize();
			fires.at(i)->SetPosition(cocos2d::Vec2(pos.x, pos.y + cur.height * 2 / 3));
			break;
		}
	}

}

void KnightSky::Collision(std::vector<Rock*> rocks)
{
	for (int i = 0; i < rocks.size(); i++)
	{
		if (rocks.at(i)->IsAlive())
		{
			if (GetRect().intersectsCircle(rocks.at(i)->GetPosition(), RADIUS_ROCK))
			{
				CCLOG("xyz");
			}
		}

		for (int j = 0; j < fires.size(); j++)
		{
			if (fires.at(j)->GetRect().intersectsCircle(rocks.at(i)->GetPosition(), RADIUS_ROCK))
			{
				fires.at(j)->SetAlive(false);
				rocks.at(i)->SetAlive(false);
			}
		}

	}


}

bool KnightSky::OnTouchBegan(cocos2d::Touch * touch, cocos2d::Event * evt)
{
	auto locationShip = mSprite->getPosition();
	auto locationTouch = touch->getLocation();
	if (locationTouch.x < locationShip.x + mSprite->getContentSize().width / 2 &&
		locationTouch.x > locationShip.x - mSprite->getContentSize().width / 2 &&
		locationTouch.y < locationShip.y + mSprite->getContentSize().width / 2 &&
		locationTouch.y > locationShip.y - mSprite->getContentSize().width / 2
		)
	{
		controlKnight = true;
		distanceTouchToDragon = locationShip - locationTouch;
	}
	return true;
}

void KnightSky::OnTouchMoved(cocos2d::Touch * touch, cocos2d::Event * evt)
{
	auto locationTouch = touch->getLocation();
	if (controlKnight)
	{
		mSprite->setPosition(locationTouch + distanceTouchToDragon);
	}
}

void KnightSky::OnTouchEnded(cocos2d::Touch * touch, cocos2d::Event * evt)
{
	controlKnight = false;
}

