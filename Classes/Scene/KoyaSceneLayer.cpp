//
//  KoyaSceneLayer.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "KoyaSceneLayer.h"
#include <ui/CocosGUI.h>

USING_NS_CC;

using namespace ui;


#pragma mark - enum

enum {
    Z_HAIKEI,
    Z_NIWATORI,
    Z_BUTTON
};


#pragma mark - create

Scene* KoyaSceneLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = KoyaSceneLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}


#pragma mark - init

bool KoyaSceneLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    mGamenSize = Director::getInstance()->getVisibleSize();
    
    return true;
}

