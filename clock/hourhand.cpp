#include "hourhand.h"


bool hourhand::init(){
	return true;
}

 cocos2d::CCSprite * hourhand::GetSprite(){
	return this->m_sprite;
}

void hourhand::BindSprite(cocos2d::CCSprite * sprite){
	this->m_sprite = sprite;
	this->m_sprite->setAnchorPoint(cocos2d::ccp(0, 0.5f));
	this->m_sprite->setScale(0.5f);
	this->m_sprite->setRotation(-90);
	this->addChild(m_sprite);
}