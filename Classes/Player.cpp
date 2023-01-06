#include "player.h"

USING_NS_CC;
Action* action;
OurPlayer::OurPlayer(cocos2d::Layer* layer) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("picos.plist", "pico.png");
	Pico = Sprite::createWithSpriteFrameName("pico.png");
	Pico->setScale(2);
	Pico->setPosition(Point(origin.x + 150, origin.y + 100));
	auto  Playerbody = PhysicsBody::createBox(Size(Pico->getContentSize().width, Pico->getContentSize().height), PhysicsMaterial(0, 0, 0));
	Playerbody->setCollisionBitmask(1);
	Playerbody->setContactTestBitmask(true);
	Playerbody->setRotationEnable(false);
	Pico->setPhysicsBody(Playerbody);
	layer->addChild(Pico, 1);
};

cocos2d::Vec2 OurPlayer::getposition() {
	return Pico->getPosition();
}

void  OurPlayer::setposition(float x, float y) {
	Pico->setPosition(Point(x, y));
}


cocos2d::Rect OurPlayer::getrect() {
	return Pico->getBoundingBox();
}



void OurPlayer::turnLeft(float z) {
	Pico->setRotation3D(Vec3(0, z, 0));
}
void OurPlayer::setScale(float x) {
	Pico->setScale(x);
}
void OurPlayer::turnRight()
{
	int x = Pico->getRotation3D().y;
	if (x == 180)
	{
		Pico->setRotation3D(Vec3(0, 0, 0));
	}

}

cocos2d::Action* OurPlayer::getWalkAnimation()
{
	Vector<SpriteFrame*> animFrames;
	char spriteFrameByName[11] = { 0 };

	for (int index = 2; index <= 7; index++)
	{
		log("%s", spriteFrameByName);
		sprintf(spriteFrameByName, "picos%d.png", index);


		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);

		animFrames.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1);
	Action* action = RepeatForever::create(Animate::create(animation));
	return action;
}



cocos2d::Action* OurPlayer::getStandAnimation()
{
	Vector<SpriteFrame*> animFrames;
	auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("picos.png");
	animFrames.pushBack(frame);
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1);
	Action* action = RepeatForever::create(Animate::create(animation));
	return action;
}

void OurPlayer::StartAnimation(Action* x)
{
	Pico->runAction(x);
}

void OurPlayer::StopAnimation(Action* x)
{
	Pico->stopAction(x);
}

void OurPlayer::StopAllAnimation()
{
	Pico->stopAllActions();
}