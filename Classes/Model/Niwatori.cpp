//
//  Niwatori.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "Niwatori.h"


#pragma mark - init

bool Niwatori::init()
{
    if (!Node::init()) {
        return false;
    }
    
    initImage();
    initEventListener();
    
    return true;
}

void Niwatori::initImage()
{
    auto image = Sprite::create("niwatori.png");
    image->setAnchorPoint(Vec2(0.5f, 0));
    this->addChild(image);
}

void Niwatori::initEventListener()
{
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(Niwatori::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(Niwatori::onTouchEnded, this);
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


#pragma mark - touch methods

bool Niwatori::onTouchBegan(Touch *pTouch, Event *pEvent)
{
    _tempScale = this->getScale();
    this->setScale(this->getScale() * 0.95f);
    return true;
}

void Niwatori::onTouchEnded(Touch *pTouch, Event *pEvent)
{
    this->setScale(_tempScale);
}