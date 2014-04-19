#include "ImageSprite.h"

ImageSprite * ImageSprite::create(CCTexture2D *texture, int i, int j) {

	ImageSprite *imageSprite = (ImageSprite*)ImageSprite::createWithTexture(texture,CCRect(j * 160, i* 160, 160, 160));

	if (imageSprite) {
		return imageSprite;
	}
	CC_SAFE_DELETE (imageSprite);
	return NULL;
}

void ImageSprite::onInit() {

}

bool ImageSprite::containsTouchLocation(CCTouch *touch) {
	CCPoint point = CCDirector::sharedDirector()->convertToGL(
			touch->getLocationInView());
	return this->rect().containsPoint(point);
}

CCRect ImageSprite::rect() {
	CCPoint point = getParent()->convertToWorldSpace(getPosition()); 
	CCSize size = displayFrame()->getOriginalSize();
	CCRect rect = CCRectMake(point.x,
			point.y , size.width, size.height);
	return rect;
}

CCRect ImageSprite::nextRect(CCPoint points) {
	CCPoint point = getParent()->convertToWorldSpace(points); 
	CCSize size = this->displayFrame()->getOriginalSize();
	CCRect rect = CCRectMake(point.x ,
			point.y , size.width, size.height);
	return rect;
}

bool ImageSprite::nextContainsTouchLocation(CCTouch *touch) {
	CCPoint point = CCDirector::sharedDirector()->convertToGL(
			touch->getLocationInView());
	CCPoint p1 = ccpAdd(this->getPosition(), ccp(160, 0));
	CCPoint p2 = ccpAdd(this->getPosition(), ccp(-160, 0));
	CCPoint p3 = ccpAdd(this->getPosition(), ccp(0, 160));
	CCPoint p4 = ccpAdd(this->getPosition(), ccp(0, -160));
	if (this->nextRect(p1).containsPoint(point)
			|| this->nextRect(p2).containsPoint(point)
			|| this->nextRect(p3).containsPoint(point)
			|| this->nextRect(p4).containsPoint(point)) {
		return true;
	} else
		return false;
}

void ImageSprite::setFinalPos(int finalPos) {

	m_finalPos = finalPos;
}

int ImageSprite::getFinalPos() {
	return m_finalPos;
}

void ImageSprite::setRandomPos(int randomPos) {
	m_randomPos= randomPos;
}

int ImageSprite::getRandomPos() {
	return m_randomPos;
}

void ImageSprite::setCurrentPos(int currentPos){
	m_currentPos = currentPos;
}

int ImageSprite::getCurrentPos(){
	return m_currentPos;
}

