//
//  NoharaSceneLayer.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "NoharaSceneLayer.h"
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace ui;

enum {
    Z_HAIKEI,
    Z_NIWATORI,
    Z_UI,
    Z_TOUCH_ARROW
};


#pragma mark - create

Scene* NoharaSceneLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = NoharaSceneLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

#pragma mark - init

bool NoharaSceneLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    mGamenSize = Director::getInstance()->getVisibleSize();
    
    initHaikei();
    
    return true;
}

void NoharaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_nohara.png");
    haikei->setPosition(Vec2(mGamenSize.width/2,
                             mGamenSize.height/2));
    this->addChild(haikei, Z_HAIKEI);
}