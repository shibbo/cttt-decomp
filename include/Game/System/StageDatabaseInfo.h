#pragma once

class BadgeConditionInfo {
public:
	BadgeConditionInfo();

	void registerInfo(const char *pName, int param);
	int getTypeID(int index) const;
	int getParam(int indexn) const;

	int mInfoCount; // _0
	int* mTypeIDs;  // _8
	int* mParams;   // _10
};

class StageDatabaseInfo {
public:
	StageDatabaseInfo();

	void initialize(int seasonId, int stageId, int courseId, int pageId, int collectItemNum,
		int collectLockNum, int openPageNum, int challengeTime, int badgeCondition1Param,
		char const* pBadgeCondition1, char const* pStageName, char const* pStageType, char const* pPlayer,
		char const* pClipping, bool offScreenBubble, bool disableStageEntry, bool showGhostTutorial,
		bool isGhostBusterStage);

	int mSeasonId;                           // _0
	int mStageId;                            // _4
	int mCourseId;                           // _8
	int mPageId;                             // _C
	int mStageType;                          // _10
	int mPlayerSelectType;                   // _14
	int mCollectItemNum;                     // _18
	int mCollectLockNum;                     // _1C
	int mOpenPageNum;                        // _20
	int mChallengeTime;                      // _24
	const char* mStageName;                  // _28
	BadgeConditionInfo* mBadgeConditionInfo; // _30
	bool mOffScreenBubble;                   // _38
	bool mIsValidClipping;                   // _39
	bool mDisableStageEntry;                 // _3A
	bool mShowGhostTutorial;                 // _3B
	bool mIsGhostBusterStage;                // _3C
};