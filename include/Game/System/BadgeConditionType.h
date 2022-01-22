#pragma once

#define BADGE_CONDITION_TYPE_INVALID 0
#define BADGE_CONDITION_TYPE_COIN_NUM 1
#define BADGE_CONDITION_TYPE_TOUCH_NUM 2
#define BADGE_CONDITION_TYPE_ON_SWITCH_CHECKER 3
#define BADGE_CONDITION_TYPE_OFF_SWITCH_CHECKER 4
#define BADGE_CONDITION_TYPE_GET_KINOKO_ONE_UP 5
#define BADGE_CONDITION_TYPE_RADISH_THROW_NUM 6
#define BADGE_CONDITION_TYPE_NO_DAMAGE 7
#define BADGE_CONDITION_TYPE_SWITCH_BLOCK_NUM 8
#define BADGE_CONDITION_TYPE_DOUBLE_CHERRY_NUM 9
#define BADGE_CONDITION_TYPE_GET_KINOKO_TREASURE 10
#define BADGE_CONDITION_TYPE_NO_FOUND_HEYHO 11
#define BADGE_CONDITION_TYPE_NO_PRESSED_RUN 12
#define BADGE_CONDITION_TYPE_POSTER_TOUCH_NUM 13
#define BADGE_CONDITION_TYPE_DOUBLE_BOSS_BIRD_CLONE_HIT_NUM 14
#define BADGE_CONDITION_TYPE_TERESA_KILLED_NUM 15
#define BADGE_CONDITION_TYPE_KINOPIO_BRIGADE_LIVING_NUM 16

class BadgeConditionType {
public:
	static int calcBadgeConditionTypeID(const char *pType);
	static bool isInvalid(const char *pType);
	static bool isCoinNum(const char *pType);
	static bool isTouchNum(const char *pType);
	static bool isOnSwitchChecker(const char *pType);
	static bool isOffSwitchChecker(const char *pType);
	static bool isGetKinokoOneUp(const char *pType);
	static bool isRadishThrowNum(const char *pType);
	static bool isNoDamage(const char *pType);
	static bool isSwitchBlockNum(const char *pType);
	static bool isDoubleCherryNum(const char *pType);
	static bool isGetKinokoTreasure(const char *pType);
	static bool isNoFoundHeyho(const char *pType);
	static bool isNoPressedRun(const char *pType);
	static bool isPosterTouchNum(const char *pType);
	static bool isDoubleBossBirdCloneHitNum(const char *pType);
	static bool isTeresaKilledNum(const char *pType);
	static bool isKinopioBrigadeLivingNum(const char *pType);
};