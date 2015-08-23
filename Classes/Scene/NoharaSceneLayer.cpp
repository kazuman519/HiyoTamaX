//
//  NoharaSceneLayer.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "NoharaSceneLayer.h"
#include <ui/CocosGUI.h>
#include "Niwatori.h"

USING_NS_CC;
using namespace ui;

const float MAX_JIKAN = 10.0f;

enum {
    Z_HAIKEI,
    Z_NIWATORI,
    Z_UI,
    Z_TIMER_LABEL,
    Z_TOUCH_ARROW
};

enum {
    JOUTAI_HAJIME,
    JOUTAI_RENDA,
    JOUTAI_OWARI,
    JOUTAI_KEKKA
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
    mJoutai = JOUTAI_HAJIME;
    mNokoriJikan = MAX_JIKAN;
    
    initHaikei();
    
    initTimer();
    
    this->scheduleUpdate();
    
    auto niwatori = Niwatori::create();
    niwatori->setPosition(Vec2(mGamenSize.width/2, mGamenSize.height/2));
    niwatori->setScale(0.2);
    this->addChild(niwatori);
    
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
    
    auto timerText = StringUtils::format("%.0f", MAX_JIKAN);
    mTimerLabel = Label::createWithSystemFont(timerText, "Marker Felt", 34);
    mTimerLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
    mTimerLabel->setPosition(Vec2(timerSprite->getPosition().x + timerSprite->getContentSize().width * 0.7f,
                                  timerSprite->getPosition().y - timerSprite->getContentSize().height * 0.5f));
    this->addChild(mTimerLabel, Z_TIMER_LABEL);
}


#pragma mark - update

void NoharaSceneLayer::update(float frame)
{
    if (mJoutai == JOUTAI_RENDA) {
        mNokoriJikan -= frame;
        
        if (mNokoriJikan <= 0) {
            mNokoriJikan = 10;
            mJoutai = JOUTAI_OWARI;
        }
        
        auto timerText = StringUtils::format("%.2f", mNokoriJikan);
        mTimerLabel->setString(timerText);
    }
}