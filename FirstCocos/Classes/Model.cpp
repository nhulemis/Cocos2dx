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


