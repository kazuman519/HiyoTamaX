//
//  KoyaSceneLayer.h
//  HiyoTamaX
//
//  Created by 三浦　和真 on 2015/08/23.
//
//

#ifndef __HiyoTamaX__KoyaSceneLayer__
#define __HiyoTamaX__KoyaSceneLayer__

#include "cocos2d.h"

class KoyaSceneLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(KoyaSceneLayer);

private:
    cocos2d::Size mGamenSize;
    
    void initHaikei();
    void initNiwatori();
    void initAsobikataButton();
    void initAsobuButton();
    void initZukanButton();
    void initModoruButton();
    void initDataBar();
    
    void asobikataCallback(Ref* sender);
    void asobuCallback(Ref* sender);
    void zukanCallback(Ref* sender);
    void modoruCallback(Ref* sender);
};

#endif /* defined(__HiyoTamaX__KoyaSceneLayer__) */
