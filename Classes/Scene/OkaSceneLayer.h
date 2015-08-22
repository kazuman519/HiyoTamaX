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

class OkaSceneLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(OkaSceneLayer);
    
private:
    cocos2d::Size mGamenSize;
    
    void initHaikei();
    void initButton();
    void initLogo();
    
    void gameStartCallback(Ref* sender);
};

#endif /* defined(__HiyoTamaX__HTMOkaScene__) */
