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

enum class GameState {
    HAJIME,
    RENDA,
    OWARI,
    KEKKA
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
    
    initTimer();
    
    this->scheduleUpdate();
    
    return true;
}

void NoharaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_nohara.png");
    haikei->setPosition(Vec2(mGamenSize.width/2,
                             mGamenSize.height/2));
    this->addChild(haikei, Z_HAIKEI);
}


void NoharaSceneLayer::initTimer()
{
    auto timerSprite = Sprite::create("img_timer.png");
    timerSprite->setAnchorPoint(Vec2(0, 1.0f));
    timerSprite->setPosition(Vec2(0, mGamenSize.height));
    this->addChild(timerSprite, Z_UI);
}


#pragma mark - update

void NoharaSceneLayer::update(float frame)
{
    log("fa-------------------wwww");
}