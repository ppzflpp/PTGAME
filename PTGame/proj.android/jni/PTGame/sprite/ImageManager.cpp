#include "ImageManager.h"
#include "ImageSprite.h"
#include <algorithm>
#include <vector>
using namespace std;
void ImageManager::initRandomGrid(int grid[3][3]){
	vector<int> v;
	for(int i = 0;i < 9;i++){
		v.push_back(i);
	}

	random_shuffle(v.begin(),v.end());
	std::vector<int>::iterator it = v.begin();
	for(int a = 0;a < 3;a++){
		for(int b = 0; b < 3; b++){
			grid[a][b] = *it;
			it++;
		}
	}
}

bool ImageManager::isWin(CCArray * array){
	bool result = true;
	CCObject * obj;
	CCARRAY_FOREACH(array, obj)
	{ 
		ImageSprite *imageSprite = (ImageSprite *) obj;
		CCLog("isWin,currentPos = %d,finalPos = %d",imageSprite->getCurrentPos(),imageSprite->getFinalPos());
		if(imageSprite->getCurrentPos() != imageSprite->getFinalPos())
		{
			result = false;
			//break;
		}
	}
	return result;
}
