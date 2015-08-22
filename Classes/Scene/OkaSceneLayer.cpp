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
    initButton();
    
    return true;
}

void OkaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_oka-hd.png");
    haikei->setPosition(Vec2(mGamenSize.width/2,
                             mGamenSize.height/2));
    this->addChild(haikei);
}

void OkaSceneLayer::initButton()
{
    Button* startButton = Button::create();
    startButton->setTouchEnabled(true);
    startButton->loadTextureNormal("btn_game_start_off-hd.png");
    startButton->setPosition(Vec2(mGamenSize.width/2,
                                        mGamenSize.height/2 - 20));
    startButton->addTouchEventListener(CC_CALLBACK_1(OkaSceneLayer::gameStartCallback, this));
    this->addChild(startButton);
}

void OkaSceneLayer::gameStartCallback(Ref* sender)
{
    Scene *scene = KoyaSceneLayer::createScene();
    TransitionFade* transition = TransitionFade::create(0.5f, scene);
    
    Director::getInstance()->replaceScene(transition);
}