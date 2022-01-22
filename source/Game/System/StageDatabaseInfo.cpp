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

#ifdef NON_MATCHING
StageDatabaseInfo::StageDatabaseInfo() {
	mOpenPageNum = 1;
	mOffScreenBubble = true;
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

bool StageDatabaseInfo::isPlayerKinopio() const {
	return mPlayerSelectType == PLAYER_SELECT_TYPE_KINOPIO;
}

bool StageDatabaseInfo::isPlayerKinopico() const {
	return mPlayerSelectType == PLAYER_SELECT_TYPE_KINOPICO;
}

bool StageDatabaseInfo::isPlayerKinopioAndKinopico() const {
	return mPlayerSelectType == PLAYER_SELECT_TYPE_KINOPIO_AND_KINOPICO;
}

bool StageDatabaseInfo::isBadgeInvalid(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_INVALID;
}

bool StageDatabaseInfo::isBadgeCoinNum(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_COIN_NUM;
}

bool StageDatabaseInfo::isBadgeTouchNum(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_TOUCH_NUM;
}

bool StageDatabaseInfo::isBadgeOnSwitchChecker(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_ON_SWITCH_CHECKER;
}

bool StageDatabaseInfo::isBadgeOffSwitchChecker(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_OFF_SWITCH_CHECKER;
}

bool StageDatabaseInfo::isBadgeGetKinokoOneUp(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_GET_KINOKO_ONE_UP;
}

bool StageDatabaseInfo::isBadgeRadishThrowNum(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_RADISH_THROW_NUM;
}

bool StageDatabaseInfo::isBadgeNoDamage(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_NO_DAMAGE;
}

bool StageDatabaseInfo::isBadgeSwitchBlockNum(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_SWITCH_BLOCK_NUM;
}

bool StageDatabaseInfo::isBadgeDoubleCherryNum(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_DOUBLE_CHERRY_NUM;
}

bool StageDatabaseInfo::isBadgeGetKinokoTreasure(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_GET_KINOKO_TREASURE;
}

bool StageDatabaseInfo::isBadgeNoFoundHeyho(int index) const {
	return mBadgeConditionInfo->getTypeID(index) == BADGE_CONDITION_TYPE_NO_FOUND_HEYHO;
}