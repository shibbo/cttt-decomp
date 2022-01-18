#pragma once

#define STAGE_TYPE_NORMAL 0
#define STAGE_TYPE_BONUS 1
#define STAGE_TYPE_GAME_OVER_MINI_GAME 2
#define STAGE_TYPE_PICTURE_DEMO 3
#define STAGE_TYPE_PICTURE 4
#define STAGE_TYPE_PROLOGUE 5
#define STAGE_TYPE_SPECIAL_3D_WORLD 6
#define STAGE_TYPE_SPECIAL_MANECK 7
#define STAGE_TYPE_SPECIAL_CHERRY 8
#define STAGE_TYPE_SPECIAL_PROLOGUE 9
#define STAGE_TYPE_SPECIAL_BONUS 10
#define STAGE_TYPE_SPECIAL_OTHER 11
#define STAGE_TYPE_TRICK_ART 12
#define STAGE_TYPE_WHITE 13
#define STAGE_TYPE_LABYRINTH 14

class StageType {
public:
    static int calcStageTypeID(const char *pName);
    static bool isNormal(const char *pName);
    static bool isBonus(const char *pName);
    static bool isGameOverMiniGame(const char *pName);
    static bool isPictureDemo(const char *pName);
    static bool isPicture(const char *pName);
    static bool isPrologue(const char *pName);
    static bool isSpecial3DWorld(const char *pName);
    static bool isSpecialManeck(const char *pName);
    static bool isSpecialCherry(const char *pName);
    static bool isSpecialPrologue(const char *pName);
    static bool isSpecialBonus(const char *pName);
    static bool isSpecialOther(const char *pName);
    static bool isTrickArt(const char *pName);
    static bool isWhite(const char *pName);
};