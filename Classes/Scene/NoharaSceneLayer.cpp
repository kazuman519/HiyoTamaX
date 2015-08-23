//
//  NoharaSceneLayer.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "NoharaSceneLayer.h"
#include "Niwatori.h"

const float MAX_JIKAN = 10.0f;

enum {
    Z_HAIKEI,
    Z_NIWATORI,
    Z_UI,
    Z_TIMER_LABEL,
    Z_TOUCH_ARROW,
    Z_SIGN
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
    
    _gamenSize = Director::getInstance()->getVisibleSize();
    _joutai = JOUTAI_HAJIME;
    _nokoriJikan = MAX_JIKAN;
    
    initHaikei();
    initNiwatori();
    
    initTimer();
    
    this->scheduleUpdate();
    
    return true;
}

void NoharaSceneLayer::initHaikei()
{
    auto haikei = Sprite::create("bg_nohara.png");
    haikei->setPosition(Vec2(_gamenSize
                             .width/2,
                             _gamenSize.height/2));
    this->addChild(haikei, Z_HAIKEI);
}

void NoharaSceneLayer::initNiwatori()
{
    auto niwatori = Niwatori::create();
    niwatori->setAnchorPoint(Vec2(0.5f, 0));
    niwatori->setScale(0.75f);
    niwatori->setPosition(Vec2(niwatori->getBoundingBox().size.width/2 + 25,
                               100));
    this->addChild(niwatori, Z_NIWATORI);
}

void NoharaSceneLayer::initTimer()
{
    
    auto timerSprite = Sprite::create("img_timer.png");
    timerSprite->setAnchorPoint(Vec2(0, 1.0f));
    timerSprite->setPosition(Vec2(0, _gamenSize.height));
    this->addChild(timerSprite, Z_UI);
    
    auto timerText = StringUtils::format("%0.1f", MAX_JIKAN);
    _timerLabel
    = Label::createWithSystemFont(timerText, "Marker Felt", 34);
    _timerLabel->setAnchorPoint(Vec2(1.0f, 0.5f));
    _timerLabel
    ->setPosition(Vec2(timerSprite->getPosition().x + timerSprite->getContentSize().width * 0.7f,
                                  timerSprite->getPosition().y - timerSprite->getContentSize().height * 0.5f));
    this->addChild(_timerLabel, Z_TIMER_LABEL);
}


#pragma mark - scene methods

void NoharaSceneLayer::onEnterTransitionDidFinish()
{
    startGame();
}


#pragma mark - update

void NoharaSceneLayer::update(float frame)
{
    if (_joutai == JOUTAI_RENDA) {
        _nokoriJikan -= frame;
        
        if (_nokoriJikan <= 0) {
            _nokoriJikan = 0;
            _joutai = JOUTAI_OWARI;
        }
        
        auto timerText = StringUtils::format("%.1f", _nokoriJikan);
        _timerLabel->setString(timerText);
    }
}


#pragma mark - game methods

void NoharaSceneLayer::startGame()
{
    auto sprite = Sprite::create("img_start_sign.png");
    sprite->setPosition(Vec2(_gamenSize.width/2,
                             _gamenSize.height/2));
    sprite->setScale(0);
    this->addChild(sprite, Z_SIGN);
    
    auto scale = ScaleTo::create(0.2f, 1.0f);
    auto rotate = RotateTo::create(0.2f, 720);
    auto spawn = Spawn::create(scale, rotate, NULL);
    
    auto callFunc = CallFunc::create([this]() {
        _joutai = JOUTAI_RENDA;
    });
    
    auto delay = DelayTime::create(0.5f);
    
    auto fade = FadeTo::create(0.5f, 0);
    
    auto sequence = Sequence::create(spawn, callFunc, delay, fade, NULL);
    
    sprite->runAction(sequence);
}