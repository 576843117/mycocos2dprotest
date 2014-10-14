#ifndef __MINUTE_LAYER__
#define __MINUTE_LAYER__
#include "cocos2d.h"
class minute:public cocos2d::CCLayer
{
public:
	virtual bool init();
	cocos2d::CCSprite * GetSprite();
	void BindSprite(cocos2d::CCSprite* sprite);
private:
	cocos2d::CCSprite * m_sprite;
};

#endif