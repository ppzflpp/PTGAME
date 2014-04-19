#ifndef __IMAGE_SPRITE_H__
#define __IMAGE_SPRITE_H__

#include "cocos2d.h"
using namespace cocos2d;
class ImageSprite : public CCSprite{
public:
	static ImageSprite *create(CCTexture2D *texture,int rowIndex,int columIndex);
	bool containsTouchLocation(CCTouch * touch);
	bool nextContainsTouchLocation(CCTouch *touch);
	void onInit();
	void setRandomPos(int randomPos);
	int getRandomPos();
	void setFinalPos(int finalPos);
	int getFinalPos();
	void setCurrentPos(int currentPos); 
	int getCurrentPos();
	int m_randomPos;//random position
	int m_finalPos;//final position
	int m_currentPos;

private:
	CCRect rect();
	CCRect nextRect(CCPoint point);
};

#endif
