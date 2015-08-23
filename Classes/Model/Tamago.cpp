//
//  Tamago.cpp
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#include "Tamago.h"


#pragma mark - init

bool Tamago::init()
{
    if (!Node::init()) {
        return false;
    }
    
    return true;
}