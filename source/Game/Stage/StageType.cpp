#include "Game/Stage/StageType.h"
#include "Game/al/Util.h"

int StageType::calcStageTypeID(const char *pStage) {
    if (al::isEqualString(pStage, "通常")) {
        return 0;
    }

    if (al::isEqualString(pStage, "ボーナス")) {
        return 1;
    }

    if (al::isEqualString(pStage, "ミニゲーム")) {
        return 2;
    }

    if (al::isEqualString(pStage, "挿絵デモ")) {
        return 3;
    }

    if (al::isEqualString(pStage, "挿絵")) {
        return 4;
    }

    if (al::isEqualString(pStage, "プロローグ")) {
        return 5;
    }

    if (al::isEqualString(pStage, "特殊(3Dワールド)")) {
        return 6;
    }

    if (al::isEqualString(pStage, "特殊(マネック)")) {
        return 7;
    }

    if (al::isEqualString(pStage, "特殊(チェリー)")) {
        return 8;
    }

    if (al::isEqualString(pStage, "特殊(プロローグ)")) {
        return 9;
    }

    if (al::isEqualString(pStage, "特殊(ボーナス)")) {
        return 10;
    }

    if (al::isEqualString(pStage, "特殊(その他)")) {
        return 11;
    }

    if (al::isEqualString(pStage, "トリックアート")) {
        return 12;
    }

    if (al::isEqualString(pStage, "白紙")) {
        return 13;
    }

    if (al::isEqualString(pStage, "Labyrinth")) {
        return 14;
    }

    return 0;
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