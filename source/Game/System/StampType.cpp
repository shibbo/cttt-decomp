#include "Game/System/StampType.h"
#include "Game/al/Util.h"

int StampType::calcStampTypeID(const char *pName) {
	if (al::isEqualString(pName, "Course")) {
		return STAMP_TYPE_COURSE;
	}
	if (al::isEqualString(pName, "Default")) {
		return STAMP_TYPE_DEFAULT;
	}
	if (al::isEqualString(pName, "MarioComplete")) {
		return STAMP_TYPE_MARIO_COMPLETE;
	}
	if (al::isEqualString(pName, "LuigiComplete")) {
		return STAMP_TYPE_LUIGI_COMPLETE;
	}
	if (al::isEqualString(pName, "PeachComplete")) {
		return STAMP_TYPE_PEACH_COMPLETE;
	}
	if (al::isEqualString(pName, "KinopioComplete")) {
		return STAMP_TYPE_KINOPIO_COMPLETE;
	}
	if (al::isEqualString(pName, "RosettaComplete")) {
		return STAMP_TYPE_ROSETTA_COMPLETE;
	}

	return 0;
}

bool StampType::isCourse(const char *pName) {
	return al::isEqualString(pName, "Course");
}

bool StampType::isDefault(const char *pName) {
	return al::isEqualString(pName, "Default");
}

bool StampType::isMarioComplete(const char *pName) {
	return al::isEqualString(pName, "MarioComplete");
}

bool StampType::isLuigiComplete(const char *pName) {
	return al::isEqualString(pName, "LuigiComplete");
}

bool StampType::isPeachComplete(const char *pName) {
	return al::isEqualString(pName, "PeachComplete");
}

bool StampType::isKinopioComplete(const char *pName) {
	return al::isEqualString(pName, "KinopioComplete");
}

bool StampType::isRosettaComplete(const char *pName) {
	return al::isEqualString(pName, "RosettaComplete");
}