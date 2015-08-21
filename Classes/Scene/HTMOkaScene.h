//
//  HTMOkaScene.h
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/21.
//
//

#ifndef __HiyoTamaX__HTMOkaScene__
#define __HiyoTamaX__HTMOkaScene__

#include "cocos2d.h"

class Oka : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(Oka);
    
private:
    cocos2d::Size mGamenSize;
    cocos2d::Vec2 mGamenPosition;
    
    void initBackground();
    void initButton();
    
    void hajimariCallback();
};

#endif /* defined(__HiyoTamaX__HTMOkaScene__) */
