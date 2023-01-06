#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
using namespace cocos2d;
//creating a class representing every image in the layer in other word every square in the layer surface and walls
class OurPlayer
{

public:
	cocos2d::Vec2 getposition();
	void setposition(float x, float y);
	cocos2d::Rect getrect();
	void turnLeft(float z);
	void setScale(float x);
	void turnRight();
	cocos2d::Action* getWalkAnimation();
	cocos2d::Action* getStandAnimation();
	void StartAnimation(Action* x);
	void StopAnimation(Action* x);
	void StopAllAnimation();
	OurPlayer(cocos2d::Layer* layer);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	//desctructor
	//this is where we initiate the sprite with a file path,
	cocos2d::Sprite* Pico;

};
#endif