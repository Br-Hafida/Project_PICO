#ifndef _MYWORLD_SCENE_H_
#define _MYWORLD_SCENE_H_
#include "cocos2d.h"
#include "player.h"
#include "key.h"
#include "door.h"


class niveau1: public cocos2d::Layer
{
public:
    void update(float dt);
    void moveright(float dt);
    void moveleft(float dt);
    void movetop(float dt);
    void movebot(float dt);
    void launch(float dt);
    void canonAnime(float dt);
    int hits = 0;
    bool isUpPressed = false;
    bool isDpressed = false;
    bool isApressed = false;
    bool isSpacePressed = false;
    bool isDoorOpened = false;
    bool isOnGround = true;
    bool isKeyCollected = false;
    static cocos2d::Scene* createScene();

    virtual bool init();
    bool onContactBegin(cocos2d::PhysicsContact& contact);



    // implement the "static create()" method manually
    CREATE_FUNC(niveau1);
    OurPlayer* player;
    OurKey* key;
    OurDoor* door;
    Sprite* ground;
    Sprite* bullet;
    Sprite* canon;
    Action* Boom;
    Action* walk;
    Action* stand;

};

#endif // _MYWORLD_SCENE_H_