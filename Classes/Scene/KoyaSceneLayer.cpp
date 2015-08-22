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