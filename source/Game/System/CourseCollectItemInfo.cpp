#include "Game/System/CourseCollectItemInfo.h"

CourseCollectItemInfo::CourseCollectItemInfo() {
	mCollectItemFlags = 0;
}

void CourseCollectItemInfo::initialize() {
	mCollectItemFlags = 0;
}

void CourseCollectItemInfo::copy(const CourseCollectItemInfo &rSrc) {
	mCollectItemFlags = rSrc.mCollectItemFlags;
}

//int CourseCollectItemInfo::calcCollectItemAcquireNum(int a2) const;

bool CourseCollectItemInfo::isCompleteAcquire(int numCollectItem) const {
	if (numCollectItem < 1)
		return true;

	int bit = 0;

	while (mCollectItemFlags & (1 << bit)) {
		if (++bit >= numCollectItem)
			return true;
	}

	return false;
}