#include "Menu.h"
#include "niveau1.h"
#include "niveaux.h"
#include "cocostudio/SimpleAudioEngine.h"


USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    LayerColor* _bgColor = LayerColor::create(Color4B(255, 255, 255, 255));
    this->addChild(_bgColor, -10);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto logo = Sprite::create("title.png");
    logo->setPosition(Vec2(visibleSize.width - 800, visibleSize.height / 1.4));
    this->addChild(logo, -4);
    logo->setScale(0.9);

    auto playItem = MenuItemFont::create("niveaux", CC_CALLBACK_1(MainMenu::GoToSelectLevels, this));
    playItem->setColor(Color3B::BLACK);
    playItem->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 1));
    auto playItem2 = MenuItemFont::create("Play", CC_CALLBACK_1(MainMenu::GoToHelloWorldScene, this));
    playItem2->setColor(Color3B::BLACK);
    playItem2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 4) * 2));
    auto menu = Menu::create(playItem, playItem2, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);

    return true;
}



void MainMenu::GoToHelloWorldScene(cocos2d::Ref* pSender)
{

    auto scene = niveau1::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}


void MainMenu::GoToSelectLevels(cocos2d::Ref* pSender)
{

    auto scene = niveaux::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}
