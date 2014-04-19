#ifndef __PT_SCENE_H__
#define __PT_SCENE_H__

#include "cocos2d.h"
#include "ImageSprite.h"

#define GRID_LENGTH 3

class PTScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
    virtual void registerWithTouchDispatcher();

    virtual void onEnter();

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(PTScene);

private:
    cocos2d::CCArray *pSpriteArray;
    cocos2d::CCSpriteBatchNode *pBatchNode;
    cocos2d::CCTouch *pBeginTouch;
    ImageSprite *pSelectImage;
    int m_randomPos[GRID_LENGTH][GRID_LENGTH];

};

#endif // __PT_SCENE_H__
