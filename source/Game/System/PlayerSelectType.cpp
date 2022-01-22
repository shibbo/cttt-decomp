#include "Game/System/PlayerSelectType.h"
#include "Game/al/Util.h"

int PlayerSelectType::calcPlayerSelectTypeID(const char *pType) {
	if (al::isEqualString(pType, "キノピオ"))
		return PLAYER_SELECT_TYPE_KINOPIO;

	if (al::isEqualString(pType, "キノピコ"))
		return PLAYER_SELECT_TYPE_KINOPICO;

	if (al::isEqualString(pType, "キノピオ＆キノピコ"))
		return PLAYER_SELECT_TYPE_KINOPIO_AND_KINOPICO;

	return PLAYER_SELECT_TYPE_KINOPIO;
}

bool PlayerSelectType::isKinopio(const char *pType) {
	return al::isEqualString(pType, "キノピオ");
}

bool PlayerSelectType::isKinopico(const char *pType) {
	return al::isEqualString(pType, "キノピコ");
}

bool PlayerSelectType::isKinopioAndKinopico(const char *pType) {
	return al::isEqualString(pType, "キノピオ＆キノピコ");
}