#include "PTScene.h"
#include "ImageManager.h"
#include "SimpleAudioEngine.h"
#include "ImageSprite.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* PTScene::scene() {
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	PTScene *layer = PTScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PTScene::init() {
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init()) {
		return false;
	}

	char* imagePath = "girls/beauty_1.jpg";

	CCSize size = CCDirector::sharedDirector()->getWinSize();

	ImageManager::initRandomGrid(m_randomPos);

	pBatchNode = CCSpriteBatchNode::create(imagePath, 9);

	setTouchEnabled(true);

	int w = 0;
	for (int i = 0; i < GRID_LENGTH; i++) {
		for (int j = 0; j < GRID_LENGTH; j++) {
			ImageSprite *_pImageSprite = ImageSprite::create(
					pBatchNode->getTexture(), i,j);

			_pImageSprite->setAnchorPoint(ccp(0, 0));
			int n = m_randomPos[i][j]/GRID_LENGTH;
			int m = m_randomPos[i][j]%GRID_LENGTH;
			_pImageSprite->setPosition(
					ccp(m* 160,(GRID_LENGTH-1- n) * 160)); 

			if (_pImageSprite) {
				_pImageSprite->setFinalPos(w);
				_pImageSprite->setCurrentPos(m_randomPos[i][j]);
				_pImageSprite->setRandomPos(m_randomPos[i][j]);
				w++;
				if (pBatchNode) {
					pBatchNode->addChild(_pImageSprite);
				}
			} else {
				CCLog("NULL....i = %d,j=%d,get sprite fail");
			}

		}
	}
	
	CCSize contentSize = pBatchNode->getTexture()->getContentSize();
	pBatchNode->setAnchorPoint(ccp(0, 0));
	pBatchNode->setPosition(ccp((size.width-contentSize.width) / 2, (size.height-contentSize.height) / 2) );
	this->addChild(pBatchNode, 0);

	CCLabelTTF* pLabel = CCLabelTTF::create("GAME", "Marker Felt", 50);

	pLabel->setPosition(ccp(size.width / 2, size.height - 20));

	this->addChild(pLabel, 1);

	return true;
}

void PTScene::menuCloseCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void PTScene::onEnter() {
	//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,1, false);
	CCLayer::onEnter();
}

void PTScene::registerWithTouchDispatcher() {
	//CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(
			this, 1, false);
}

bool PTScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
	pBeginTouch = pTouch;
	CCArray *ccArray = pBatchNode->getChildren();
	CCObject *obj;
	bool tag = false;
	CCARRAY_FOREACH(ccArray, obj)
	{
		ImageSprite *imageSprite = (ImageSprite*) obj;
		if (imageSprite->containsTouchLocation(pTouch)) {
			tag = true;
			pSelectImage = imageSprite;
			break;
		} else {
			//CCLog("touch no sprite");
		}
	}
	if (tag == false) {
		pSelectImage = NULL;
	}
	return true;
}

void PTScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
}

void PTScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent) {
	CCArray * ccArray = pBatchNode->getChildren();
	CCObject *obj;
	CCARRAY_FOREACH(ccArray, obj)
	{
		ImageSprite *imageSprite = (ImageSprite *) obj;
		bool result = imageSprite->containsTouchLocation(pTouch);
		if (result && pSelectImage != NULL) {

			if (imageSprite->getPosition().equals(
					pSelectImage->getPosition())) {
				return;
			} else if (pSelectImage->nextContainsTouchLocation(pTouch)) {

				CCPoint point = imageSprite->getPosition();
				imageSprite->setPosition(pSelectImage->getPosition());
				pSelectImage->setPosition(point);

				int temp = imageSprite->getCurrentPos();
				imageSprite->setCurrentPos(pSelectImage->getCurrentPos());
				pSelectImage->setCurrentPos(temp);
				
				if (ImageManager::isWin(ccArray)) {
					CCLog("You Win !!!");
					CCSprite * winSprite = CCSprite::create("win.png");
					winSprite->setPosition(
							ccp(
									CCDirector::sharedDirector()->getWinSize().width
											/ 2,
									CCDirector::sharedDirector()->getWinSize().height
											/ 2));
					winSprite->runAction(CCScaleTo::create(1.0f, 1.4f));
					addChild(winSprite);
				}else{
					
				}
				return;
			}else{
			}
		}
	}
}

