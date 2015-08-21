//
//  HazimariScene.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/21.
//
//

#include "HazimariScene.h"

USING_NS_CC;

Scene* Hazimari::createScene()
{
    auto scene = Scene::create();
    auto layer = Hazimari::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool Hazimari::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    Size gamenSize = Director::getInstance()->getVisibleSize();
    Vec2 gamenPosition = Director::getInstance()->getVisibleSize();
    
    
}

void Hazimari::createHaikei()
{
    
}