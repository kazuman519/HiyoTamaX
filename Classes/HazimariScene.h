//
//  HazimariScene.h
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/21.
//
//

#ifndef __HiyoTamaX__HazimariScene__
#define __HiyoTamaX__HazimariScene__

#include "cocos2d.h"

class HazimariScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(HazimariScene);
    
private:
    cocos2d::Size mGamenSize;
    cocos2d::Vec2 mGamenPosition;
    
    void initHaikei();
};

#endif /* defined(__HiyoTamaX__HazimariScene__) */