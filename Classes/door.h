#ifndef _DOOR_H_
#define _DOOR_H_

#include "cocos2d.h"
using namespace cocos2d;

class OurDoor
{

public:
	bool exist;
	cocos2d::Vec2 getposition();
	void setposition(float x, float y);
	void setposition2(float x, float y);
	cocos2d::Rect getrect();
	void OpenDoor();
	void setScale(float x);
	OurDoor(cocos2d::Layer* layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	//desctructor
	//this is where we initiate the sprite with a file path,
	cocos2d::Sprite* Door;
	cocos2d::Sprite* OpenedDoor;
};
#endif