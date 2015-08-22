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
    
    initHaikei();
    initNiwatori();
    initAsobikataButton();
    initAsobuButton();
    
    return true;
}

void KoyaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_koya.png");
    haikei->setPosition(Vec2(mGamenSize.width/2,
                             mGamenSize.height/2));
    this->addChild(haikei);
}

void KoyaSceneLayer::initNiwatori()
{
    auto niwatori = Sprite::create("niwatori.png");
    niwatori->setPosition(Vec2(niwatori->getContentSize().width/3,
                               niwatori->getContentSize().height/4));
    this->addChild(niwatori);
    
    // 反転
    auto flip = FlipX::create(true);
    niwatori->runAction(flip);
}

void KoyaSceneLayer::initAsobikataButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_asobikata.png");
    button->setAnchorPoint(Vec2(0, 1.0));
    button->setPosition(Vec2(4, mGamenSize.height - 4));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::asobikataCallback, this));
    this->addChild(button);
}

void KoyaSceneLayer::initAsobuButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_asobu.png");
    button->setAnchorPoint(Vec2(1.0, 1.0));
    button->setPosition(Vec2(mGamenSize.width - 4,
                             mGamenSize.height - 4));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::asobuCallback, this));
    this->addChild(button);
}

#pragma mark - callback

void KoyaSceneLayer::asobikataCallback(Ref* sender)
{
    
}

void KoyaSceneLayer::asobuCallback(Ref* sender)
{
    
}