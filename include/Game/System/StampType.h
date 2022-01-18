#pragma once

#define STAMP_TYPE_COURSE 0
#define STAMP_TYPE_DEFAULT 1
#define STAMP_TYPE_MARIO_COMPLETE 2
#define STAMP_TYPE_LUIGI_COMPLETE 3
#define STAMP_TYPE_PEACH_COMPLETE 4
#define STAMP_TYPE_KINOPIO_COMPLETE 5
#define STAMP_TYPE_ROSETTA_COMPLETE 6

class StampType {
public:
	static int calcStampTypeID(const char *pName);
	static bool isCourse(const char *pName);
	static bool isDefault(const char *pName);
	static bool isMarioComplete(const char *pName);
	static bool isLuigiComplete(const char *pName);
	static bool isPeachComplete(const char *pName);
	static bool isKinopioComplete(const char *pName);
	static bool isRosettaComplete(const char *pName);
};