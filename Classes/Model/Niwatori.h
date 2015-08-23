//
//  Niwatori.h
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#ifndef __HiyoTamaX__Niwatori__
#define __HiyoTamaX__Niwatori__

#include "cocos2d.h"

USING_NS_CC;


class Niwatori : public Sprite
{
public:
    virtual bool init();
    
    bool onTouchBegan(Touch* pTouch, Event* pEvent);
    void onTouchEnded(Touch* pTouch, Event* pEvent);
    
    CREATE_FUNC(Niwatori);
    
private:
    float _tempScale;
    
    void initEventListener();
    
    void actionTsujou();
    void actionUmu();
    void actionOdoroku();
    void actionTsukareta();
};

#endif /* defined(__HiyoTamaX__Niwatori__) */
