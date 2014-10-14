#include "second.h"

bool second::init(){
	return true;
}

cocos2d::CCSprite * second::GetSprite(){
	return this->m_sprite;
}

void second::BindSprite(cocos2d::CCSprite * sprite){
	m_sprite = sprite;
	m_sprite->setAnchorPoint(cocos2d::ccp(0, 0.5f));
	m_sprite->setScale(0.5f);
	m_sprite->setRotation(-90);
	this->addChild(m_sprite);
}