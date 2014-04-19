#ifndef __IMAGE_MANAGER_H__
#define __IMAGE_MANAGER_H__

#include "cocos2d.h"
using namespace cocos2d;
class ImageManager{
public:
	static void initRandomGrid(int grid[3][3]);
	static bool isWin(CCArray *);


};

#endif
