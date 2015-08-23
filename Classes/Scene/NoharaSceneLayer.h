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
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace ui;

class NoharaSceneLayer : public Layer
{
public:
    static Scene* createScene();
    
    virtual bool init();
    
    void update(float frame);
    
    CREATE_FUNC(NoharaSceneLayer);
    
private:
    Size _gamenSize;
    int _joutai;
    float _nokoriJikan;
    
    Label* _timerLabel;
    
    void initHaikei();
    void initNiwatori();
    void initTouchArrow();
    void initTimer();
    void initTamagoNumLabel();
};

#endif /* defined(__HiyoTamaX__NoharaSceneLayer__) */
