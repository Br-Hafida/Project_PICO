#include "key.h"

USING_NS_CC;

OurKey::OurKey(cocos2d::Layer* layer) {
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	Pico = Sprite::create("key.png");
	Pico->setScale(0.25);
	Pico->setPosition(Point(origin.x + 50, origin.y + 70));
	layer->addChild(Pico, 1);
};

cocos2d::Vec2 OurKey::getposition() {
	return Pico->getPosition();
}

void  OurKey::setposition(float x, float y) {
	Pico->setPosition(Point(x, y));
}
void OurKey::removeFromParent() {
	Pico->setVisible(false);
}
cocos2d::Rect OurKey::getrect() {
	return Pico->getBoundingBox();
}
void OurKey::setScale(float x) {
	Pico->setScale(x);
}