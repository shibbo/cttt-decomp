#pragma once

#include "Game/al/LiveActor/NerveExecutor.h"

namespace al {
	void setNerve(IUseNerve *pUseNerve, const Nerve *pNerve);
	void setNerveAtStep(IUseNerve *pUseNerve, const Nerve *pNerve, int step);
	bool isStep(const IUseNerve *pUseNerve, int step);
	bool isNerve(const IUseNerve *pUseNerve, const Nerve *pNerve);
	int getNerveStep(const IUseNerve *pUseNerve);
	bool isFirstStep(const IUseNerve *pUseNerve);
	bool isLessStep(const IUseNerve *pUseNerve, int step);
	bool isLessEqualStep(const IUseNerve *pUseNerve, int step);
	bool isGreaterStep(const IUseNerve *pUseNerve, int step);
	bool isGreaterEqualStep(const IUseNerve *pUseNerve, int step);
	bool isIntervalStep(const IUseNerve *pUseNerve, int interval, int startStep);
	bool isIntervalOnOffStep(const IUseNerve *pUseNerve, int interval, int startStep);
	bool isNewNerveStep(const IUseNerve *pUseNerve);

	// There is much more
};