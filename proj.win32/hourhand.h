#ifndef __HOURHAND_LAYER__
#define __HOURHAND_LAYER__
#include "cocos2d.h"

class hourhand:public cocos2d::CCLayer
{
public:
	virtual bool init();
	 cocos2d::CCSprite * GetSprite();
	void BindSprite(cocos2d::CCSprite * sprite);
private:
	cocos2d::CCSprite * m_sprite;
};

#endif