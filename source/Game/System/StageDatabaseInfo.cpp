#include "Game/System/StageDatabaseInfo.h"
#include "Game/System/BadgeConditionType.h"
#include "Game/System/PlayerSelectType.h"
#include "Game/System/StageType.h"
#include "Game/al/Util.h"

BadgeConditionInfo::BadgeConditionInfo() {
	mInfoCount = 0;
	mTypeIDs = new int[1];
	mParams = new int[1];
	*mTypeIDs = BADGE_CONDITION_TYPE_INVALID;
	*mParams = 0;
}

void BadgeConditionInfo::registerInfo(const char *pName, int param) {
	mTypeIDs[mInfoCount] = BadgeConditionType::calcBadgeConditionTypeID(pName);
	mParams[mInfoCount] = param;
	mInfoCount++;
}

int BadgeConditionInfo::getTypeID(int index) const {
	return mTypeIDs[index];
}

int BadgeConditionInfo::getParam(int index) const {
	return mParams[index];
}

#ifdef NON_MATCHING // wtf is going on here
StageDatabaseInfo::StageDatabaseInfo() {
	mStageType = 0;
	mPlayerSelectType = 0;
	mCollectItemNum = 0;
	mCollectLockNum = 0;
	mOpenPageNum = 1;
	mChallengeTime = 0;
	mBadgeConditionInfo = nullptr;
	mStageName = nullptr;
	mOffScreenBubble = 0;
	mIsValidClipping = true;
	mDisableStageEntry = 0;
	mShowGhostTutorial = 0;
	mIsGhostBusterStage = 0;
	mSeasonId = 0;
	mStageId = 0;
	mCourseId = 0;
	mPageId = 0;

	mBadgeConditionInfo = new BadgeConditionInfo();
}
#endif

#ifdef NON_MATCHING // mStageType = StageType::calcStageTypeID loads the pointer param later than intended
void StageDatabaseInfo::initialize(int seasonId, int stageId, int courseId, int pageId, int collectItemNum,
	int collectLockNum, int openPageNum, int challengeTime, int badgeCondition1Param,
	char const* pBadgeCondition1, char const* pStageName, char const* pStageType, char const* pPlayer,
	char const* pClipping, bool offScreenBubble, bool disableStageEntry, bool showGhostTutorial,
	bool isGhostBusterStage)
{
	mSeasonId = seasonId;
	mStageId = stageId;
	mCollectItemNum = collectItemNum;
	mCollectLockNum = collectLockNum;
	mStageName = pStageName;
	mCourseId = courseId;
	mPageId = pageId;
	mOpenPageNum = openPageNum;
	mChallengeTime = challengeTime;
	mStageType = StageType::calcStageTypeID(pStageType);
	mPlayerSelectType = PlayerSelectType::calcPlayerSelectTypeID(pPlayer);
	mOffScreenBubble = offScreenBubble;
	mDisableStageEntry = disableStageEntry;
	mShowGhostTutorial = showGhostTutorial;
	mIsGhostBusterStage = isGhostBusterStage;
	
	if (!BadgeConditionType::isInvalid(pBadgeCondition1)) {
		mBadgeConditionInfo->registerInfo(pBadgeCondition1, badgeCondition1Param);
	}

	mIsValidClipping = !al::isEqualString(pClipping, "無効");
}
#endif