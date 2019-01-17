#include "KnightSky.h"
#include "Define.h"
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
	listener->onTouchBegan = CC_CALLBACK_2(KnightSky::OnTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(KnightSky::OnTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(KnightSky::OnTouchEnded, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, scene);
	Init();
}

KnightSky::~KnightSky()
{

}

void KnightSky::Update()
{
	
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

bool KnightSky::OnTouchBegan(cocos2d::Touch * touch, cocos2d::Event * evt)
{
	return true;
}

void KnightSky::OnTouchMoved(cocos2d::Touch * touch, cocos2d::Event * evt)
{
	
}

void KnightSky::OnTouchEnded(cocos2d::Touch * touch, cocos2d::Event * evt)
{
}

