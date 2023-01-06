#ifndef _KEY_H_
#define _KEY_H_

#include "cocos2d.h"
using namespace cocos2d;
class OurKey
{
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* Pico;

public:
	cocos2d::Vec2 getposition();
	void setposition(float x, float y);
	cocos2d::Rect getrect();
	void removeFromParent();
	void setScale(float x);
	OurKey(cocos2d::Layer* layer);

};
#endif