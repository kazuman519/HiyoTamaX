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

class Hazimari : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(Hazimari);
};

#endif /* defined(__HiyoTamaX__HazimariScene__) */
