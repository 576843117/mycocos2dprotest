#include "bgclock.h"

#include "cocos2d.h"
USING_NS_CC;

cocos2d::CCScene * bgclock::createScene(){
	bgclock * layer = bgclock::create();
	cocos2d::CCScene * scene = cocos2d::CCScene::create();
	scene->addChild(layer);
	return scene;
}

bool bgclock::init(){
	cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
	cocos2d::CCSprite *bg = cocos2d::CCSprite::create("background.jpg");
	bg->setPosition(cocos2d::ccp(size.width / 2, size.height / 2));
	bg->setScale(0.5f);
	this->addChild(bg);

	//hour hand
	hour_sprite = (hourhand *)hourhand::create();//cocos2d::CCLayer::create();
	hour_sprite->BindSprite(cocos2d::CCSprite::create("shi.png"));
	h = hour_sprite->GetSprite();
	h->setPosition(cocos2d::ccp(size.width / 2, size.height / 2));
	this->addChild(h);

	//minute hand
	minute_sprite = (minute *)minute::create();//cocos2d::CCLayer::create();
	minute_sprite->BindSprite(cocos2d::CCSprite::create("fen.png"));
	m = minute_sprite->GetSprite();
	m->setPosition(cocos2d::ccp(size.width / 2, size.height / 2));
	this->addChild(m);

	//second hand
	secoone_sprite = (second *)second::create();//cocos2d::CCLayer::create();
	secoone_sprite->BindSprite(cocos2d::CCSprite::create("miao.png"));
	s = secoone_sprite->GetSprite();
	s->setPosition(cocos2d::ccp(size.width / 2, size.height / 2));
	this->addChild(s);

	//get time
	time_t   tt;
	timeval tv;
	tm  *now;
	gettimeofday(&tv, NULL);
	tt = tv.tv_sec;
	now=localtime(&tt);
	t_hour = now->tm_hour;
	t_min = now->tm_min;
	t_sec = now->tm_sec;

	this->schedule(schedule_selector(bgclock::updateTime), 1);//schedule_selector(bgclock::updateTime), 1);



	return true;
}

void bgclock::updateTime(float i){
	static int mRotation = t_min * 6;  
	static int sRotation = t_sec * 6;  

	static int hRotatio;            
									
	if (t_hour>12){                     
		hRotatio = (t_hour - 12) * 5 * 6 + (mRotation / 72) * 6;
																  
	}
	else{                             
		hRotatio = (t_hour)* 5 * 6 + (mRotation / 72) * 6;
	}

	s->setRotation(sRotation);  
	m->setRotation(mRotation);  
	h->setRotation(hRotatio);     
	if (sRotation >= 360){                
		sRotation = 0;                   	
		mRotation += 6;                  
		m->setRotation(mRotation);
		if (mRotation % 72 == 0){                 
			hRotatio += 6;                     
			h->setRotation(hRotatio);
			if (mRotation >= 360){              
				mRotation = 0;                 
			}
		}
	}
	sRotation += 6;


}