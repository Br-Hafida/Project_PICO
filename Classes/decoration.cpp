#include "HelloWorldScene.h"
#include <cocostudio/SimpleAudioEngine.h>
#include "GameScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto Scene = HelloWorld::create();
    scene->addChild(Scene);
    return scene;
}


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    return true;
}

void HelloWorld::GoToGameScene(cococs2d::Ref *pSender)
{
    auto scene = GameScreen::createScene();

    Director::getInstance()->replaceScene(scene);
}

