#pragma once

class StageUserData {
public:
	StageUserData();

	void init();
	void setFigureType(int figureType);
	void setAlive(bool alive);

	int mFigureType; // _0
	bool mIsAlive;   // _4
};