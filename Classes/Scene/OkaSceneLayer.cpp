//
//  HTMOkaScene.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/21.
//
//

#include "OkaSceneLayer.h"
#include <ui/CocosGUI.h>
#include "KoyaSceneLayer.h"

USING_NS_CC;
using namespace ui;


#pragma mark - enum

enum {
    Z_HAIKEI,
    Z_BUTTON,
    Z_LOGO
};


#pragma mark - create

Scene* OkaSceneLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = OkaSceneLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}


#pragma mark - init

bool OkaSceneLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    mGamenSize = Director::getInstance()->getVisibleSize();
    
    initHaikei();
    initButton();
    initLogo();
    
    return true;
}

void OkaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_oka.png");
    haikei->setPosition(Vec2(mGamenSize.width/2,
                             mGamenSize.height/2));
    this->addChild(haikei);
}

void OkaSceneLayer::initButton()
{
    auto startButton = Button::create();
    startButton->setTouchEnabled(true);
    startButton->loadTextureNormal("btn_game_start.png");
    startButton->setPosition(Vec2(mGamenSize.width/2,
                                        mGamenSize.height/2 - 20));
    startButton->addTouchEventListener(CC_CALLBACK_1(OkaSceneLayer::gameStartCallback, this));
    this->addChild(startButton);
}

void OkaSceneLayer::initLogo()
{
    auto logo = Sprite::create("logo_hiyotama.png");
    logo->setAnchorPoint(Vec2(0.5f, 1.0f));
    logo->setPosition(Vec2(mGamenSize.width/2,
                           mGamenSize.height - 50));
    this->addChild(logo);
}

#pragma mark - callback

void OkaSceneLayer::gameStartCallback(Ref* sender)
{
    auto scene = KoyaSceneLayer::createScene();
    auto transition = TransitionFade::create(0.5f, scene);
    
    Director::getInstance()->replaceScene(transition);
}