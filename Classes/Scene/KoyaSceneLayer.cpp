//
//  KoyaSceneLayer.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "KoyaSceneLayer.h"
#include "OkaSceneLayer.h"
#include "NoharaSceneLayer.h"


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
    
    _gamenSize = Director::getInstance()->getVisibleSize();
    
    initHaikei();
    initNiwatori();
    initAsobikataButton();
    initAsobuButton();
    initZukanButton();
    initModoruButton();
    initDataBar();
    
    return true;
}

void KoyaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_koya.png");
    haikei->setPosition(Vec2(_gamenSize.width/2,
                             _gamenSize.height/2));
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
    button->setPosition(Vec2(4, _gamenSize.height - 4));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::asobikataCallback, this));
    this->addChild(button, Z_BUTTON);
}

void KoyaSceneLayer::initAsobuButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_asobu.png");
    button->setAnchorPoint(Vec2(1.0f, 1.0f));
    button->setPosition(Vec2(_gamenSize.width - 4,
                             _gamenSize.height));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::asobuCallback, this));
    this->addChild(button, Z_BUTTON);
}

void KoyaSceneLayer::initZukanButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_zukan.png");
    button->setAnchorPoint(Vec2(1.0f, 1.0f));
    button->setPosition(Vec2(_gamenSize.width - 4,
                             _gamenSize.height - 170));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::zukanCallback, this));
    this->addChild(button, Z_BUTTON);
}

void KoyaSceneLayer::initModoruButton()
{
    auto button = Button::create();
    button->setTouchEnabled(true);
    button->loadTextureNormal("btn_modoru_oka.png");
    button->setAnchorPoint(Vec2(1.0f, 1.0f));
    button->setPosition(Vec2(_gamenSize.width - 4,
                             _gamenSize.height - 340));
    button->addTouchEventListener(CC_CALLBACK_1(KoyaSceneLayer::modoruCallback, this));
    this->addChild(button, Z_BUTTON);
}

void KoyaSceneLayer::initDataBar()
{
    auto dataBar = Sprite::create("img_data_bar.png");
    dataBar->setAnchorPoint(Vec2(1.0f, 0));
    dataBar->setPosition(Vec2(_gamenSize.width, 0));
    this->addChild(dataBar);
}


#pragma mark - callback

void KoyaSceneLayer::asobikataCallback(Ref* sender)
{
    
}

void KoyaSceneLayer::asobuCallback(Ref* sender)
{
    auto scene = NoharaSceneLayer::createScene();
    auto transition = TransitionFade::create(0.4f, scene);
    
    Director::getInstance()->replaceScene(transition);
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