#ifndef _LAVA_H_
#define _LAVA_H_

#include "cocos2d.h"
using namespace cocos2d;
//creating a class representing every image in the layer in other word every square in the layer surface and walls
class OurLava
{

public:
	bool exist;
	cocos2d::Vec2 getposition();
	void setposition(float x, float y);
	void setposition2(float x, float y);
	void setposition3(float x, float y);
	cocos2d::Rect getrect();
	void setScale(float x);
	OurLava(cocos2d::Layer* layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	//desctructor
	//this is where we initiate the sprite with a file path,
	cocos2d::Sprite* lava;
	cocos2d::Sprite* lavaAnimation;
	cocos2d::Sprite* lavaAnimation2;
};
#endif