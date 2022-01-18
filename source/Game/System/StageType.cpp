#include "Game/System/StageType.h"
#include "Game/al/Util.h"

int StageType::calcStageTypeID(const char *pName) {
    if (al::isEqualString(pName, "通常")) {
        return STAGE_TYPE_NORMAL;
    }

    if (al::isEqualString(pName, "ボーナス")) {
        return STAGE_TYPE_BONUS;
    }

    if (al::isEqualString(pName, "ミニゲーム")) {
        return STAGE_TYPE_GAME_OVER_MINI_GAME;
    }

    if (al::isEqualString(pName, "挿絵デモ")) {
        return STAGE_TYPE_PICTURE_DEMO;
    }

    if (al::isEqualString(pName, "挿絵")) {
        return STAGE_TYPE_PICTURE;
    }

    if (al::isEqualString(pName, "プロローグ")) {
        return STAGE_TYPE_PROLOGUE;
    }

    if (al::isEqualString(pName, "特殊(3Dワールド)")) {
        return STAGE_TYPE_SPECIAL_3D_WORLD;
    }

    if (al::isEqualString(pName, "特殊(マネック)")) {
        return STAGE_TYPE_SPECIAL_MANECK;
    }

    if (al::isEqualString(pName, "特殊(チェリー)")) {
        return STAGE_TYPE_SPECIAL_CHERRY;
    }

    if (al::isEqualString(pName, "特殊(プロローグ)")) {
        return STAGE_TYPE_SPECIAL_PROLOGUE;
    }

    if (al::isEqualString(pName, "特殊(ボーナス)")) {
        return STAGE_TYPE_SPECIAL_BONUS;
    }

    if (al::isEqualString(pName, "特殊(その他)")) {
        return STAGE_TYPE_SPECIAL_OTHER;
    }

    if (al::isEqualString(pName, "トリックアート")) {
        return STAGE_TYPE_TRICK_ART;
    }

    if (al::isEqualString(pName, "白紙")) {
        return STAGE_TYPE_WHITE;
    }

    if (al::isEqualString(pName, "Labyrinth")) {
        return STAGE_TYPE_LABYRINTH;
    }

    return STAGE_TYPE_NORMAL;
}

bool StageType::isNormal(const char *pName) {
    return al::isEqualString(pName, "通常");
}

bool StageType::isBonus(const char *pName) {
    return al::isEqualString(pName, "ボーナス");
}

bool StageType::isGameOverMiniGame(const char *pName) {
    return al::isEqualString(pName, "ミニゲーム");
}

bool StageType::isPictureDemo(const char *pName) {
    return al::isEqualString(pName, "挿絵デモ");
}

bool StageType::isPicture(const char *pName) {
    return al::isEqualString(pName, "挿絵");
}

bool StageType::isPrologue(const char *pName) {
    return al::isEqualString(pName, "プロローグ");
}

bool StageType::isSpecial3DWorld(const char *pName) {
    return al::isEqualString(pName, "特殊(3Dワールド)");
}

bool StageType::isSpecialManeck(const char *pName) {
    return al::isEqualString(pName, "特殊(マネック)");
}

bool StageType::isSpecialCherry(const char *pName) {
    return al::isEqualString(pName, "特殊(チェリー)");
}

bool StageType::isSpecialPrologue(const char *pName) {
    return al::isEqualString(pName, "特殊(プロローグ)");
}

bool StageType::isSpecialBonus(const char *pName) {
    return al::isEqualString(pName, "特殊(ボーナス)");
}

bool StageType::isSpecialOther(const char *pName) {
    return al::isEqualString(pName, "特殊(その他)");
}

bool StageType::isTrickArt(const char *pName) {
    return al::isEqualString(pName, "トリックアート");
}

bool StageType::isWhite(const char *pName) {
    return al::isEqualString(pName, "白紙");
}