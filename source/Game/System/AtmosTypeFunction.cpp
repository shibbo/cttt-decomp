#include "Game/System/AtmosTypeFunction.h"
#include "Game/al/Util.h"

int AtmosTypeFunction::calcAtmosTypeID(const char *pType) {
	if (al::isEqualString(pType, "使用しない")) {
		return ATMOS_TYPE_UNUSE;
	}

	if (al::isEqualString(pType, "使用する")) {
		return ATMOS_TYPE_SCATTER;
	}

	if (al::isEqualString(pType, "使用する(AGL)")) {
		return ATMOS_TYPE_AGL_LIGHT_SCATTER;
	}

	return ATMOS_TYPE_UNUSE;
}

bool AtmosTypeFunction::isUnuse(const char *pType) {
	return al::isEqualString(pType, "使用しない");
}

bool AtmosTypeFunction::isUseAtmosScatter(const char *pType) {
	return al::isEqualString(pType, "使用する");
}

bool AtmosTypeFunction::isUseAglLightScatter(const char *pType) {
	return al::isEqualString(pType, "使用する(AGL)");
}