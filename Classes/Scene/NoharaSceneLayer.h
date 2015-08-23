//
//  NoharaSceneLayer.h
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#ifndef __HiyoTamaX__NoharaSceneLayer__
#define __HiyoTamaX__NoharaSceneLayer__

#include "cocos2d.h"

class NoharaSceneLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void update(float frame);
    
    CREATE_FUNC(NoharaSceneLayer);
    
private:
    cocos2d::Size mGamenSize;
    int mJoutai;
    float mNokoriJikan;
    
    cocos2d::Label* mTimerLabel;
    
    void initHaikei();
    void initNiwatori();
    void initTouchArrow();
    void initTimer();
    void initTamagoNumLabel();
};

#endif /* defined(__HiyoTamaX__NoharaSceneLayer__) */
