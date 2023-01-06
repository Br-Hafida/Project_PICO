#include "niveau1.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* niveau1::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, -400));
    auto layer = niveau1::create();
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool niveau1::init()
{
    if (!Layer::init())
    {
        return false;
    }


    //---------------------------------------------create variables for positioning our instance-------------------------------------------------------

    auto visibleSize = Director::getInstance()->getWinSize();

    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //------------------------------------------------------------create backgroud -------------------------------------------------

    auto backGround = Sprite::create("Background.jpg");
    backGround->setPosition(Point((visibleSize.width ), (visibleSize.height )));
    backGround->setScale(1.8);
    this->addChild(backGround, -10);

    //-------------------------------------------------create an edge box for our game------------------------------------------------------

    auto edgebody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    edgebody->setCollisionBitmask(3);
    edgebody->setContactTestBitmask(true);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point((visibleSize.width / 2), (visibleSize.height / 2)));
    edgeNode->setPhysicsBody(edgebody);
    this->addChild(edgeNode);
    this->setScale(1.3);

    //---------------------------------------------------creating object from player key and door  classes------------------
    player = new OurPlayer(this);
    key = new OurKey(this);
    door = new OurDoor(this);


    // fountain with animation

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Start.plist", "Start.png");
    auto fountain = Sprite::createWithSpriteFrameName("Start.png");
    fountain->setPosition(Point(origin.x + 250, door->getposition().y + 20));
    fountain->setScale(2);
    this->addChild(fountain, -1);
    Vector<SpriteFrame*> animFrames;
    char spriteFrameByName[15] = { 0 };

    for (int index = 1; index <= 4; index++)
    {
        log("%s", spriteFrameByName);
        sprintf(spriteFrameByName, "Start%d.png", index);
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);

        animFrames.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1);
    auto action = RepeatForever::create(Animate::create(animation));
    fountain->runAction(action);
    //-------------------------------------------create ground and obstecales----------------------------------------------------------------


        //ground
    ground = Sprite::create("Floor.png");
    ground->setScale(2);
    auto Frame4body = PhysicsBody::createBox(Size(ground->getContentSize().width, ground->getContentSize().height), PhysicsMaterial(0, 0, 0));
    Frame4body->setCollisionBitmask(2);
    Frame4body->setContactTestBitmask(true);
    ground->setPosition(Point(origin.x + 220, origin.y + 15));
    if (Frame4body != nullptr)
    {
        Frame4body->setDynamic(false);
        ground->setPhysicsBody(Frame4body);
    }
    this->addChild(ground);

    auto gound2 = Sprite::create("Floor.png");
    gound2->setScale(2);
    auto gound2body = PhysicsBody::createBox(Size(gound2->getContentSize().width, gound2->getContentSize().height), PhysicsMaterial(0, 0, 0));
    gound2body->setCollisionBitmask(2);
    gound2body->setContactTestBitmask(true);
    gound2->setPosition(Point(origin.x + 875, origin.y + 15));
    if (gound2body != nullptr)
    {
        gound2body->setDynamic(false);
        gound2->setPhysicsBody(gound2body);
    }
    this->addChild(gound2);

    // lava






//--------------------------------------------------creating a canon with animations sheet---------------------------------------

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("canon.plist", "canon.png");
    canon = Sprite::createWithSpriteFrameName("canon1.png");
    canon->setPosition(Point(door->getposition().x + 60, door->getposition().y - 17));
    canon->setScale(1.6);
    this->addChild(canon, 3);
    //--------------------------------------------------creating a camera to follow player--------------------------------------------
    auto camera = Camera::create();
    camera->setPositionZ(5);
    camera->clearBackground();
    this->addChild(camera);
    //--------------------------------------------------------------------------------------------------------------------------------

    this->scheduleUpdate();
    //-------------------------------------------------Schedule some actions--------------------------------------------------------
    this->schedule(SEL_SCHEDULE(&niveau1::canonAnime), 1.5);
    this->schedule(SEL_SCHEDULE(&niveau1::launch), 1.5);


    //------------------------------------------------------creating an event listener for keyboard---------------------------------
    auto eventListener = EventListenerKeyboard::create();
    //------------------------------------------------------listening for keypressed---------------------------------
    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {

        switch (keyCode) {
            //case wich key is pressed
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:


            isApressed = true;
            walk = player->getWalkAnimation();
            player->StartAnimation(walk);
            player->StopAnimation(stand);
            this->schedule(SEL_SCHEDULE(&niveau1::moveleft), 0.01);



            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:

            isDpressed = true;
            walk = player->getWalkAnimation();

            player->StartAnimation(walk);
            player->StopAnimation(stand);
            this->schedule(SEL_SCHEDULE(&niveau1::moveright), 0.01);



            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
        case EventKeyboard::KeyCode::KEY_W:
            if (isSpacePressed == false)
            {
                this->schedule(SEL_SCHEDULE(&niveau1::movetop), 0.01);
                isSpacePressed = true;
                isOnGround = false;
                cocos2d::AudioEngine::preload("audio/jumpSound.mp3");
                cocos2d::AudioEngine::play2d("audio/jumpSound.mp3", false, 0.3f);
                player->StopAnimation(walk);
            }




            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:

            isUpPressed = true;

            break;

        }
    };
    //------------------------------------------------------listening if a key is released---------------------------------
    eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {

        switch (keyCode) {
            //case wich key is pressed
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            isApressed = false;
            this->unschedule(SEL_SCHEDULE(&niveau1::moveleft));
            stand = player->getStandAnimation();
            player->StartAnimation(stand);
            player->StopAnimation(walk);


            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:

            isDpressed = false;
            player->StopAnimation(walk);
            stand = player->getStandAnimation();
            player->StartAnimation(stand);
            this->unschedule(SEL_SCHEDULE(&niveau1::moveright));

            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
        case EventKeyboard::KeyCode::KEY_W:


            this->unschedule(SEL_SCHEDULE(&niveau1::movetop));

            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:

            isUpPressed = false;

            break;

        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    //we create a contact listener to detect the collision of the ball with te walls and the obstacles
    auto contactListener = EventListenerPhysicsContact::create();
    //make a call back to the function everytime a contact happen
    contactListener->onContactBegin = CC_CALLBACK_1(niveau1::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    return true;
}
void niveau1::canonAnime(float dt)
{
    Vector<SpriteFrame*> animFrames;
    char spriteFrameByName[11] = { 0 };

    for (int index = 1; index <= 5; index++)
    {
        log("%s", spriteFrameByName);
        sprintf(spriteFrameByName, "canon%d.png", index);


        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);

        animFrames.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1);
    Boom = Animate::create(animation);
    canon->runAction(Boom);
}
void niveau1::moveright(float dt) {
    Vec2 playerPos = player->getposition();
    player->setposition(playerPos.x + 80 * dt, playerPos.y);
}
void niveau1::moveleft(float dt) {
    Vec2 ballpos = player->getposition();
    player->setposition(ballpos.x - 80 * dt, ballpos.y);
}
void niveau1::movebot(float dt) {
    Vec2 ballpos = player->getposition();
    player->setposition(ballpos.x, ballpos.y - 80 * dt);
}
void niveau1::movetop(float dt) {
    Vec2 ballpos = player->getposition();
    player->setposition(ballpos.x, ballpos.y + 160 * dt);
}

void niveau1::launch(float dt)
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    bullet = Sprite::create("bullet.png");
    bullet->setScale(1.2);
    bullet->setPosition(Point(origin.x + 1000, origin.y + 68));
    auto bulletBody = PhysicsBody::createBox(Size(bullet->getContentSize().width / 4, bullet->getContentSize().height / 4), PhysicsMaterial(0, 0, 0));
    bulletBody->setCollisionBitmask(10);
    bulletBody->setContactTestBitmask(true);
    bulletBody->setDynamic(false);
    bullet->setPhysicsBody(bulletBody);
    auto fire = MoveTo::create(2, Point(origin.x, origin.y + 68));
    bullet->runAction(fire);
    this->addChild(bullet);
    cocos2d::AudioEngine::preload("audio/gun.mp3");
    cocos2d::AudioEngine::play2d("audio/gun.mp3", false, 0.3f);
}


bool niveau1::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();
    auto p = contact.getContactData()->points;

    // check if the bodies have collided
    if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
    {
        isSpacePressed = false;
        isOnGround = true;
    }
    if ((1 == a->getCollisionBitmask() && 3 == b->getCollisionBitmask()) || (3 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())) {
        if (isDpressed)
        {
            this->unschedule(SEL_SCHEDULE(&niveau1::moveright));
            player->setposition(player->getposition().x - 10, player->getposition().y);
        }
        else if (isApressed)
        {
            this->unschedule(SEL_SCHEDULE(&niveau1::moveleft));
            player->setposition(player->getposition().x + 10, player->getposition().y);
        }
    }
    if ((1 == a->getCollisionBitmask() && 10 == b->getCollisionBitmask()) || (10 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
    {
        isUpPressed = false;
        auto scene = niveau1::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(0.2, scene));
    }
    
    return true;
}



void niveau1::update(float dt) {

    Rect rect1 = player->getrect();
    Rect rect2 = key->getrect();
    Rect rect3 = door->getrect();
    Rect rect5 = ground->getBoundingBox();

    auto v = Director::getInstance()->getWinSize();
    Layer::setAnchorPoint(Vec2(player->getposition().x / v.width, player->getposition().y / v.height));

    if (rect1.intersectsRect(rect2))
    {
        key->setposition(player->getposition().x - 10, player->getposition().y + 10);
        if (!isKeyCollected)
        {
            cocos2d::AudioEngine::preload("audio/keyGet.mp3");
            cocos2d::AudioEngine::play2d("audio/keyGet.mp3", false, 0.3f);
            isKeyCollected = true;
        }



    }

}
