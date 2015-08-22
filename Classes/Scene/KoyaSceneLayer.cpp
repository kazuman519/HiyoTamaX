//
//  KoyaSceneLayer.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "KoyaSceneLayer.h"
#include <ui/CocosGUI.h>
#include "OkaSceneLayer.h"

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
    initZukanButton();
    initModoruButton();
    
    return true;
}

void KoyaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_koya.png");
    haikei->setPosition(Vec2(mGamenSize.width/2,
                             mGamenSize.height/2));
    this->addChild(haikei, Z_HAIKEI);
}

void KoyaSceneLayer::initNiwatori()
{
    auto niwatori = Sprite::create("niwatori.png");
    niwatori->setPosition(Vec2(niwatori->getContentSize().width/3,
                               niwatori->getContentSize().height/4));
    this->addChild(niwatori, Z_NIWATORI);
    
    // 反転
    auto flip = FlipX::create(true);
    niwatori->runAction(flip);
}

void KoyaSceneLayer::initAsobikataButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_asobikata.png");
    button->setAnchorPoint(Vec2(0, 1.0f));
    button->setPosition(Vec2(4, mGamenSize.height - 4));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::asobikataCallback, this));
    this->addChild(button, Z_BUTTON);
}

void KoyaSceneLayer::initAsobuButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_asobu.png");
    button->setAnchorPoint(Vec2(1.0f, 1.0f));
    button->setPosition(Vec2(mGamenSize.width - 4,
                             mGamenSize.height - 4));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::asobuCallback, this));
    this->addChild(button, Z_BUTTON);
}

void KoyaSceneLayer::initZukanButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_zukan.png");
    button->setAnchorPoint(Vec2(1.0f, 1.0f));
    button->setPosition(Vec2(mGamenSize.width - 4,
                             mGamenSize.height - 180));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::zukanCallback, this));
    this->addChild(button, Z_BUTTON);
}

void KoyaSceneLayer::initModoruButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_modoru_oka.png");
    button->setAnchorPoint(Vec2(1.0f, 1.0f));
    button->setPosition(Vec2(mGamenSize.width - 4,
                             mGamenSize.height - 360));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::modoruCallback, this));
    this->addChild(button, Z_BUTTON);
}


#pragma mark - callback

void KoyaSceneLayer::asobikataCallback(Ref* sender)
{
    
}

void KoyaSceneLayer::asobuCallback(Ref* sender)
{
    
}

void KoyaSceneLayer::zukanCallback(Ref* sender)
{
    
}

void KoyaSceneLayer::modoruCallback(Ref* sender)
{
    auto scene = OkaSceneLayer::createScene();
    auto transition = TransitionFade::create(0.3f, scene);
    
    Director::getInstance()->replaceScene(transition);
}