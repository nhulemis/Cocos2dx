#include "KnightSky.h"
#include "Define.h"
#include "fire.h"
#include "Explosion.h"

#pragma region declare
std::vector<Fire*> fires;
std::vector<Explosion*> Expls;
int frameCount = 0;

bool controlKnight = false;
cocos2d::Vec2 distanceTouchToDragon;

//Explosion *e;

int life;

#pragma endregion


KnightSky::KnightSky(cocos2d::Scene * scene)
{
	//Explosion* e = new Explosion(scene);
	mSprite = cocos2d::Sprite::create();
	SetAlive(true);
	auto animation = createAnimation(DRAGON_KNIGHT_IMG, 4, 0.15);
	auto sequence = cocos2d::Sequence::create(cocos2d::Animate::create(animation),
		nullptr
	);
	mSprite->runAction(cocos2d::RepeatForever::create(sequence));
	mSprite->setPosition(SCREEN_W / 2, SCREEN_H / 10);
	mSprite->setScale(1.2);
	mSprite->setPositionZ(2);
	scene->addChild(mSprite);

	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(KnightSky::OnTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(KnightSky::OnTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(KnightSky::OnTouchEnded, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, scene);

	for (int i = 0; i < MAX_FIRE; i++)
	{
		fires.push_back(new Fire(scene));
	}

	for (int i = 0; i < MAX_ROCK_ON_SCREEN; i++)
	{
		Expls.push_back(new Explosion(scene));
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

	if (frameCount %40 == 0)
	{
		for (int i = 0; i < MAX_ROCK_ON_SCREEN; i++)
		{
			Expls.at(i)->SetAlive(false);
		}
	}
}

void KnightSky::Init()
{
	life = 3;
}




void KnightSky::SetAlive(bool status)
{
	mAlive = status;
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

void KnightSky::Collision(std::vector<Rock*> rocks, cocos2d::Scene * scene)
{
	for (int i = 0; i < rocks.size(); i++)
	{
		auto _rock = rocks.at(i);
		if (_rock->IsAlive())
		{
			if (GetRect().intersectsCircle(_rock->GetPosition(), RADIUS_ROCK))
			{
				CCLOG("xyz");
			//	Explosion(scene, mSprite->getPosition());
				Expls.at(i)->SetPosExplotion(mSprite->getPosition());
				SetAlive(false);
				/*if (life <= 0)
				{
					SetAlive(false);
					return;
				}
				life--;
				auto fadeIn = cocos2d::FadeIn::create(0.5);
				auto fadeOut = cocos2d::FadeOut::create(0);
				auto seq = cocos2d::Sequence::create(
					fadeOut, fadeIn,
					fadeOut->clone(), fadeIn->clone(),
					nullptr
				);
				mSprite->runAction(seq);
				continue;*/
			}
		}

		for (int j = 0; j < fires.size(); j++)
		{
			if (fires.at(i)->IsAlive())
			{
				if (fires.at(j)->GetRect().intersectsCircle(_rock->GetPosition(), RADIUS_ROCK))
				{
					 //inclue setAlive false					
					Expls.at(i)->SetPosExplotion(_rock->GetPosition());
					fires.at(j)->SetAlive(false);
					_rock->SetAlive(false);
				}
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
	auto locationTouch = touch->getLocation() + distanceTouchToDragon;
	if (controlKnight &&
		locationTouch.x >=0 &&
		locationTouch.x <= SCREEN_W  &&
		locationTouch.y >= 0 &&
		locationTouch.y <= SCREEN_H
		)
	{
		mSprite->setPosition(locationTouch);
	}
}

void KnightSky::OnTouchEnded(cocos2d::Touch * touch, cocos2d::Event * evt)
{
	controlKnight = false;
}

