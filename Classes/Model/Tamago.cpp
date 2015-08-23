//
//  Tamago.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "Tamago.h"


#pragma mark - init

bool Tamago::initWithNumber(int number)
{
    std::string fileName = StringUtils::format("tamago_%d.png", number);
    if (!Sprite::initWithFile(fileName)) {
        return false;
    }
    
    return true;
}