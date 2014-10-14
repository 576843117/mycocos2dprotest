#ifndef __bgclock_SCENE_H__
#define __bgclock_SCENE_H__
#include<iostream>
#include "cocos2d.h"
#include "hourhand.h"
#include "minute.h"
#include "second.h"
class bgclock :
	public cocos2d::CCLayer
{
public:
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();


	void updateTime(float i);
	// a selector callback
	//void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(bgclock);
	hourhand * hour_sprite;
	minute *  minute_sprite;
	second * secoone_sprite;

	cocos2d::CCSprite * h;
	cocos2d::CCSprite * m;
	cocos2d::CCSprite * s;
public:
	int  t_hour=0;
	int t_min=0;
	int t_sec=0;
};

#endif