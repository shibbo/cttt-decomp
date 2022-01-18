#include "Game/System/StageUserData.h"
#include "Game/Util.h"

StageUserData::StageUserData() {
	mFigureType = kp::getPlayerFigureTypeDefault();
	mIsAlive = false;
}

void StageUserData::init() {
	mFigureType = kp::getPlayerFigureTypeDefault();
	mIsAlive = false;
}

void StageUserData::setFigureType(int figureType) {
	mFigureType = figureType;
}

void StageUserData::setAlive(bool alive) {
	mIsAlive = alive;
}