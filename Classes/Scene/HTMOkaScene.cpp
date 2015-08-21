//
//  HTMOkaScene.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/21.
//
//

#include "HTMOkaScene.h"

USING_NS_CC;

Scene* Oka::createScene()
{
    auto scene = Scene::create();
    auto layer = Layer::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool Oka::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    return true;
}