//
//  Tamago.h
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#ifndef __HiyoTamaX__Tamago__
#define __HiyoTamaX__Tamago__

#include "cocos2d.h"

USING_NS_CC;

class Tamago : public Node
{
public:
    virtual bool init();
    
    CREATE_FUNC(Tamago);
    
private:
    void initImage();
};

#endif /* defined(__HiyoTamaX__Tamago__) */
