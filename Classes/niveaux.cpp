#include "niveaux.h"
#include "niveau1.h"
//#include "AudioEngine.h"


USING_NS_CC;

Scene* niveaux::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = niveaux::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool niveaux::init()
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

    auto playItem3 = MenuItemFont::create("niveau1", CC_CALLBACK_1(niveaux::GoToNiveau1Scene, this));
    playItem3->setColor(Color3B::BLACK);
    playItem3->setPosition(Point((visibleSize.width / 2) - 30, (visibleSize.height / 4) + 200));
    auto playItemImg3 = MenuItemImage::create("niveau1.jpg", "niveau1.jpg", CC_CALLBACK_1(niveaux::GoToNiveau1Scene, this));
    playItemImg3->setPosition(Point((visibleSize.width / 2) - 50, (visibleSize.height / 4)));
    playItemImg3->setScale(0.9);
    auto menu = Menu::create(playItem3, playItemImg3, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);

    return true;
}



void niveaux::GoToNiveau1Scene(cocos2d::Ref* pSender)
{

    auto scene = niveau1::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}




