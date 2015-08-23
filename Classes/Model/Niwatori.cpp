//
//  Niwatori.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "Niwatori.h"

USING_NS_CC;


#pragma mark - create


bool Niwatori::init()
{
    if (!Node::init()) {
        return false;
    }
    
    log("init niwatori");
    
    auto image = Sprite::create("niwatori.png");
    this->addChild(image);
    
    return true;
}