#include "Game/al/LiveActor/NerveUtil.h"

namespace al {
	void setNerve(IUseNerve *pUseNerve, const Nerve *pNerve) {
		pUseNerve->getNerveKeeper()->setNerve(pNerve);
	}

	void setNerveAtStep(IUseNerve *pUseNerve, const Nerve *pNerve, int step) {
		if (pUseNerve->getNerveKeeper()->mStep == step) {
			pUseNerve->getNerveKeeper()->setNerve(pNerve);
		}
	}

	bool isStep(const IUseNerve *pUseNerve, int step) {
		return pUseNerve->getNerveKeeper()->mStep == step;
	}

	bool isNerve(const IUseNerve *pUseNerve, const Nerve *pNerve) {
		return pUseNerve->getNerveKeeper()->getCurrentNerve() == pNerve;
	}

	int getNerveStep(const IUseNerve *pUseNerve) {
		return pUseNerve->getNerveKeeper()->mStep;
	}

	bool isFirstStep(const IUseNerve *pUseNerve) {
		return pUseNerve->getNerveKeeper()->mStep == 0;
	}

	bool isLessStep(const IUseNerve *pUseNerve, int step) {
		return pUseNerve->getNerveKeeper()->mStep < step;
	}

	bool isLessEqualStep(const IUseNerve *pUseNerve, int step) {
		return pUseNerve->getNerveKeeper()->mStep <= step;
	}

	bool isGreaterStep(const IUseNerve *pUseNerve, int step) {
		return pUseNerve->getNerveKeeper()->mStep > step;
	}

	bool isGreaterEqualStep(const IUseNerve *pUseNerve, int step) {
		return pUseNerve->getNerveKeeper()->mStep >= step;
	}

	bool isIntervalStep(const IUseNerve *pUseNerve, int interval, int startStep) {
		return (pUseNerve->getNerveKeeper()->mStep - startStep) % interval == 0;
	}

	bool isIntervalOnOffStep(const IUseNerve *pUseNerve, int interval, int startStep) {
		return ((pUseNerve->getNerveKeeper()->mStep - startStep) / interval & 1) == 0;
	}
}