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
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace ui;

class KoyaSceneLayer : public Layer
{
public:
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(KoyaSceneLayer);

private:
    Size _gamenSize;
    
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
