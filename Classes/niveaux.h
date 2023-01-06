#ifndef NIVEAUX_H
#define NIVEAUX_H

#include "cocos2d.h"


class niveaux : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(niveaux);


    void GoToNiveau1Scene(cocos2d::Ref* pSender);

};

#endif // MAIN_MENU_SCENE_H