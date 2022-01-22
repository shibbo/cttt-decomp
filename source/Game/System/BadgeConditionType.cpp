#include "Game/System/BadgeConditionType.h"
#include "Game/al/Util.h"

int BadgeConditionType::calcBadgeConditionTypeID(const char *pType) {
	if (al::isEqualString(pType, "無し")) {
		return BADGE_CONDITION_TYPE_INVALID;
	}

	if (al::isEqualString(pType, "コイン取得数")) {
		return BADGE_CONDITION_TYPE_COIN_NUM;
	}

	if (al::isEqualString(pType, "タッチ回数")) {
		return BADGE_CONDITION_TYPE_TOUCH_NUM;
	}

	if (al::isEqualString(pType, "お題監視がON")) {
		return BADGE_CONDITION_TYPE_ON_SWITCH_CHECKER;
	}

	if (al::isEqualString(pType, "お題監視がOFF")) {
		return BADGE_CONDITION_TYPE_OFF_SWITCH_CHECKER;
	}

	if (al::isEqualString(pType, "1UPキノコ取得")) {
		return BADGE_CONDITION_TYPE_GET_KINOKO_ONE_UP;
	}

	if (al::isEqualString(pType, "カブ投げ回数")) {
		return BADGE_CONDITION_TYPE_RADISH_THROW_NUM;
	}

	if (al::isEqualString(pType, "ノーダメージ")) {
		return BADGE_CONDITION_TYPE_NO_DAMAGE;
	}

	if (al::isEqualString(pType, "スイッチ数")) {
		return BADGE_CONDITION_TYPE_SWITCH_BLOCK_NUM;
	}

	if (al::isEqualString(pType, "ダブルチェリー")) {
		return BADGE_CONDITION_TYPE_DOUBLE_CHERRY_NUM;
	}

	if (al::isEqualString(pType, "お宝キノコ取得")) {
		return BADGE_CONDITION_TYPE_GET_KINOKO_TREASURE;
	}

	if (al::isEqualString(pType, "ヘイホーに見つからない")) {
		return BADGE_CONDITION_TYPE_NO_FOUND_HEYHO;
	}

	if (al::isEqualString(pType, "NoPressedRun")) {
		return BADGE_CONDITION_TYPE_NO_PRESSED_RUN;
	}

	if (al::isEqualString(pType, "PosterTouchNum")) {
		return BADGE_CONDITION_TYPE_POSTER_TOUCH_NUM;
	}

	if (al::isEqualString(pType, "DoubleBossBirdCloneHitNum")) {
		return BADGE_CONDITION_TYPE_DOUBLE_BOSS_BIRD_CLONE_HIT_NUM;
	}

	if (al::isEqualString(pType, "TeresaKilledNum")) {
		return BADGE_CONDITION_TYPE_TERESA_KILLED_NUM;
	}

	if (al::isEqualString(pType, "KinopioBrigadeLivingNum")) {
		return BADGE_CONDITION_TYPE_KINOPIO_BRIGADE_LIVING_NUM;
	}

	return BADGE_CONDITION_TYPE_INVALID;
}

bool BadgeConditionType::isInvalid(const char *pType) {
	return al::isEqualString(pType, "無し");
}

bool BadgeConditionType::isCoinNum(const char *pType) {
	return al::isEqualString(pType, "コイン取得数");
}

bool BadgeConditionType::isTouchNum(const char *pType) {
	return al::isEqualString(pType, "タッチ回数");
}

bool BadgeConditionType::isOnSwitchChecker(const char *pType) {
	return al::isEqualString(pType, "お題監視がON");
}

bool BadgeConditionType::isOffSwitchChecker(const char *pType) {
	return al::isEqualString(pType, "お題監視がOFF");
}

bool BadgeConditionType::isGetKinokoOneUp(const char *pType) {
	return al::isEqualString(pType, "1UPキノコ取得");
}

bool BadgeConditionType::isRadishThrowNum(const char *pType) {
	return al::isEqualString(pType, "カブ投げ回数");
}

bool BadgeConditionType::isNoDamage(const char *pType) {
	return al::isEqualString(pType, "ノーダメージ");
}

bool BadgeConditionType::isSwitchBlockNum(const char *pType) {
	return al::isEqualString(pType, "スイッチ数");
}

bool BadgeConditionType::isDoubleCherryNum(const char *pType) {
	return al::isEqualString(pType, "ダブルチェリー");
}

bool BadgeConditionType::isGetKinokoTreasure(const char *pType) {
	return al::isEqualString(pType, "お宝キノコ取得");
}

bool BadgeConditionType::isNoFoundHeyho(const char *pType) {
	return al::isEqualString(pType, "ヘイホーに見つからない");
}

bool BadgeConditionType::isNoPressedRun(const char *pType) {
	return al::isEqualString(pType, "NoPressedRun");
}

bool BadgeConditionType::isPosterTouchNum(const char *pType) {
	return al::isEqualString(pType, "PosterTouchNum");
}

bool BadgeConditionType::isDoubleBossBirdCloneHitNum(const char *pType) {
	return al::isEqualString(pType, "DoubleBossBirdCloneHitNum");
}

bool BadgeConditionType::isTeresaKilledNum(const char *pType) {
	return al::isEqualString(pType, "TeresaKilledNum");
}

bool BadgeConditionType::isKinopioBrigadeLivingNum(const char *pType) {
	return al::isEqualString(pType, "KinopioBrigadeLivingNum");
}