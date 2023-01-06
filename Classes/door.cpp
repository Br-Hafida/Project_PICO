#include "door.h"

USING_NS_CC;

OurDoor::OurDoor(cocos2d::Layer* layer) {
	visibleSize = Director::getInstance()->getVisibleSize();
	auto s = Director::getInstance()->getWinSize();
	origin = Director::getInstance()->getVisibleOrigin();
	Door = Sprite::create("door.png");
	Door->setScale(0.30);
	Door->setPosition(Point(s.width - 100, origin.y + 90));
	OpenedDoor = Sprite::create("doorOpen.png");
	OpenedDoor->setScale(0.3);
	OpenedDoor->setPosition(Point(s.width - 100, origin.y + 90));
	OpenedDoor->setVisible(false);

	layer->addChild(Door, -1);
	layer->addChild(OpenedDoor, -1);
};

cocos2d::Vec2 OurDoor::getposition() {
	return Door->getPosition();
}

void  OurDoor::setposition(float x, float y) {
	Door->setPosition(Point(x, y));
	OpenedDoor->setPosition(Point(x, y));
}

void  OurDoor::setposition2(float x, float y) {
	OpenedDoor->setPosition(Point(x, y));
}

void OurDoor::OpenDoor() {
	Door->setVisible(false);
	OpenedDoor->setVisible(true);
	exist = false;
}

cocos2d::Rect OurDoor::getrect() {
	return Door->getBoundingBox();
}
void OurDoor::setScale(float x) {
	Door->setScale(x);
	OpenedDoor->setScale(x);
}