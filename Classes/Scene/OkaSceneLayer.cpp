//
//  HTMOkaScene.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/21.
//
//

#include "OkaSceneLayer.h"

USING_NS_CC;

enum {
    Z_HAIKEI,
    Z_BUTTON,
    Z_LOGO
};

Scene* OkaSceneLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = OkaSceneLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool OkaSceneLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    mGamenSize = Director::getInstance()->getVisibleSize();
    
    initHaikei();
    
    return true;
}

void OkaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_oka-hd.png");
    haikei->setPosition(Vec2(mGamenSize.width/2,
                             mGamenSize.height/2));
    
    this->addChild(haikei);
}