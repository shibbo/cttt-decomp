#pragma once

class CourseCollectItemInfo {
public:
	CourseCollectItemInfo();

	void initialize();
	void copy(const CourseCollectItemInfo &rSrc);
	int calcCollectItemAcquireNum(int) const;
	bool isCompleteAcquire(int numCollectItem) const;

	int mCollectItemFlags;
};