//
//  HazimariScene.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/21.
//
//

#include "HazimariScene.h"

USING_NS_CC;

enum {
    Z_HAIKEI
};

Scene* HazimariScene::createScene()
{
    auto scene = Scene::create();
    auto layer = HazimariScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool HazimariScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    mGamenSize = Director::getInstance()->getWinSize();
    mGamenPosition = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(mGamenPosition.x + mGamenSize.width/2,
                            mGamenPosition.y + mGamenSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);

    
    initHaikei();
    
    return true;
}

void HazimariScene::initHaikei()
{
    auto haikei = Sprite::create("HelloWorld.png");
    haikei->setAnchorPoint(Vec2::ZERO);
    haikei->setContentSize(Size(10, mGamenSize.height));
    printf("%f", haikei->getContentSize().width);
//    haikei->setPosition(Vec2(mGamenSize.width/2+mGamenPosition.x, mGamenSize.height/2 + mGamenPosition.y));
    
    this->addChild(haikei, Z_HAIKEI);
}