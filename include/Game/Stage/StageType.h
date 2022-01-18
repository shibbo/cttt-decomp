#pragma once

class StageType {
public:
    static int calcStageTypeID(const char *);
    static bool isNormal(const char *);
    static bool isBonus(const char *);
    static bool isGameOverMiniGame(const char *);
    static bool isPictureDemo(const char *);
    static bool isPicture(const char *);
    static bool isPrologue(const char *);
    static bool isSpecial3DWorld(const char *);
    static bool isSpecialManeck(const char *);
    static bool isSpecialCherry(const char *);
    static bool isSpecialPrologue(const char *);
    static bool isSpecialBonus(const char *);
    static bool isSpecialOther(const char *);
    static bool isTrickArt(const char *);
    static bool isWhite(const char *);
};