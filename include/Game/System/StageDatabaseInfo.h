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
	bool isStageNormal() const;
	bool isStageBonus() const;
	bool isStageGameOverMiniGame() const;
	bool isStageTrickArt() const;
	bool isStagePictureDemo() const;
	bool isStagePicture() const;
	bool isStagePrologue() const;
	bool isStageSpecialBonus() const;
	bool isStageSpecial() const;
	bool isStageSpecial3DWorld() const;
	bool isStageSpecialManeck() const;
	bool isStageSpecialCherry() const;
	bool isStageSpecialPrologue() const;
	bool isStageSpecialOther() const;
	bool isStageLabyrinth() const;
	bool isStageWhite() const;
	bool isPlayerKinopio() const;
	bool isPlayerKinopico() const;
	bool isPlayerKinopioAndKinopico() const;
	bool isBadgeInvalid(int index) const;
	bool isBadgeCoinNum(int index) const;
	bool isBadgeTouchNum(int index) const;
	bool isBadgeOnSwitchChecker(int index) const;
	bool isBadgeOffSwitchChecker(int index) const;
	bool isBadgeGetKinokoOneUp(int index) const;
	bool isBadgeRadishThrowNum(int index) const;
	bool isBadgeNoDamage(int index) const;
	bool isBadgeSwitchBlockNum(int index) const;
	bool isBadgeDoubleCherryNum(int index) const;
	bool isBadgeGetKinokoTreasure(int index) const;
	bool isBadgeNoFoundHeyho(int index) const;

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