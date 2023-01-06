#include "lavas.h"

USING_NS_CC;

OurLava::OurLava(cocos2d::Layer* layer) {
	visibleSize = Director::getInstance()->getVisibleSize();
	auto s = Director::getInstance()->getWinSize();
	origin = Director::getInstance()->getVisibleOrigin();
	lava = Sprite::create("lava.png");
	lava->setScale(0.30);
	lava->setPosition(Point(origin.x + 525, origin.y + 10));
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("lavas.plist", "lavas.png");
	lavaAnimation = Sprite::createWithSpriteFrameName("lava1.png");
	lavaAnimation->setScale(0.4);
	lavaAnimation->setPosition(Point(origin.x + 525, origin.y + 30));
	lavaAnimation2 = Sprite::createWithSpriteFrameName("lava1.png");
	lavaAnimation2->setScale(0.5);
	lavaAnimation2->setPosition(Point(origin.x + 560, origin.y + 30));
	Vector<SpriteFrame*> animFrames;
	char spriteFrameByName[15] = { 0 };

	for (int index = 1; index <= 11; index++)
	{
		log("%s", spriteFrameByName);
		sprintf(spriteFrameByName, "lava%d.png", index);
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);

		animFrames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1);
	auto action2 = RepeatForever::create(Animate::create(animation));;
	auto action = RepeatForever::create(Animate::create(animation));
	lavaAnimation->runAction(action);
	lavaAnimation2->runAction(action2);
	layer->addChild(lava, -1);
	layer->addChild(lavaAnimation, -1);
	layer->addChild(lavaAnimation2);
};

cocos2d::Vec2 OurLava::getposition() {
	return lava->getPosition();
}

void  OurLava::setposition(float x, float y) {
	lava->setPosition(Point(x, y));
}

void  OurLava::setposition2(float x, float y) {
	lavaAnimation->setPosition(Point(x, y));
}
void  OurLava::setposition3(float x, float y) {
	lavaAnimation2->setPosition(Point(x, y));
}




cocos2d::Rect OurLava::getrect() {
	return lava->getBoundingBox();
}
void OurLava::setScale(float x) {
	lava->setScale(x);
	lavaAnimation->setScale(x + 0.1);
	lavaAnimation2->setScale(x + 0.2);
}