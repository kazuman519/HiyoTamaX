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
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace ui;

class OkaSceneLayer : public Layer
{
public:
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(OkaSceneLayer);
    
private:
    Size _gamenSize;
    
    void initHaikei();
    void initButton();
    void initLogo();
    
    void gameStartCallback(Ref* sender);
};

#endif /* defined(__HiyoTamaX__HTMOkaScene__) */
