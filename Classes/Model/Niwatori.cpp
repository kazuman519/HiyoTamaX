//
//  Niwatori.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "Niwatori.h"
#include "Tamago.h"


#pragma mark - init

bool Niwatori::init()
{
    if (!Sprite::initWithFile("niwatori.png")) {
        return false;
    }
    
    _isEnabled = false;
    _tempScale = this->getScale();

    initEventListener();
    
    return true;
}

void Niwatori::initEventListener()
{
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(Niwatori::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(Niwatori::onTouchEnded, this);
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


#pragma mark - setter

void Niwatori::setEnabled(bool isEnabled)
{
    _isEnabled = isEnabled;
}


#pragma mark - touch methods

bool Niwatori::onTouchBegan(Touch *pTouch, Event *pEvent)
{
    if (!_isEnabled) {
        return false;
    }
    
    // TODO:大きくするのアニメーションで大きくしたい
    _tempScale = this->getScale();
    this->setScale(this->getScale() * 1.05f);
    
    actionSanran();
    
    return true;
}

void Niwatori::onTouchEnded(Touch *pTouch, Event *pEvent)
{
    this->setScale(_tempScale);
}


#pragma mark - action methods

/**
 * 卵を産むアクション
 */
void Niwatori::actionSanran()
{
    // 卵生成
    auto tamago = Tamago::createWithNumber(1);
    tamago->setPosition(Vec2(this->getPosition().x + this->getBoundingBox().size.width * 0.3,
                             this->getPosition().y + this->getBoundingBox().size.height * 0.4));
    tamago->setRotation(rand() % 360);
    this->getParent()->addChild(tamago, this->getLocalZOrder() - 1);
    
    // アクション
    auto jump = JumpBy::create(0.5f,
                               Vec2(this->getBoundingBox().size.width * 0.5f,
                                    this->getPositionY() - tamago->getBoundingBox().origin.y
                                    ), 200, 1);
    auto move = MoveBy::create(4, Vec2(this->getParent()->getContentSize().width,
                                       0));
    auto sequence = Sequence::create(jump, move, NULL);
    auto rotate = RotateTo::create(5, 10000);
    auto spawn = Spawn::create(sequence, rotate, NULL);
    
    tamago->runAction(spawn);
}

/**
 * 振り向くアクション
 */
void Niwatori::actionFurimuku()
{
    auto flipX = ScaleTo::create(0.2f, -this->getScaleX(), this->getScaleY());
    
    this->runAction(flipX);
}