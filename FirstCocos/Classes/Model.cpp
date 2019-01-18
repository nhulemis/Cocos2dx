#include "Model.h"


Model::Model()
{
}


Model::~Model()
{
}

void Model::SetAlive(bool status)
{
	mAlive = status;
	mSprite->setVisible(mAlive);
}

bool Model::IsAlive()
{
	return mAlive;
}

cocos2d::Rect Model::GetRect()
{
	return mSprite->getBoundingBox();
}

cocos2d::Animation * Model::createAnimation(std::string name, int frames, float delay)
{
	cocos2d::Vector<cocos2d::SpriteFrame*> _frames;
	for (int i = 1; i <= frames; i++)
	{
		char buffer[20] = { 0 };
		sprintf(buffer, "%d.png", i);
		std::string _name = name + buffer;
		auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(_name);
		_frames.pushBack(frame);
	}
	auto anima = cocos2d::Animation::createWithSpriteFrames(_frames, delay);
	return anima;
}




