#ifndef __SECOND_HAND__
#define __SECOND_HAND__
#include "cocos2d.h"
class second:public cocos2d::CCLayer
{
public:
	virtual bool init();
	cocos2d::CCSprite * GetSprite();
	void BindSprite(cocos2d::CCSprite * sprite);
private:
	cocos2d::CCSprite * m_sprite;
};

#endif