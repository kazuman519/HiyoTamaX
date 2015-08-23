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

class Tamago : public Sprite
{
public:
    static Tamago* createWithNumber(int number)
    {
        Tamago *tamago = new Tamago();
        if (tamago && tamago->initWithNumber(number))
        {
            tamago->autorelease();
            return tamago;
        }
        CC_SAFE_DELETE(tamago);
        return nullptr;
    }
    
    virtual bool initWithNumber(int number);
    
private:
    void initImage();
};

#endif /* defined(__HiyoTamaX__Tamago__) */
