#pragma once

#include "Game/al/LiveActor/LiveActor.h"
#include "Game/al/LiveActor/NerveExecutor.h"

#define NERVE_HEADER(Class, Action) \
    class Class ## Nrv ## Action : public al::Nerve { \
    public: \
        void execute(al::NerveKeeper*) override; \
    }; \
    Class ## Nrv ## Action nrv ## Action;

#define NERVE_IMPL_(Class, Action, ActionFunc) \
    void Class ## Nrv ## Action::execute(al::NerveKeeper* keeper) { \
        static_cast<Class*>(keeper->mParent)->exe ## ActionFunc(); \
    }
#define NERVE_IMPL(Class, Action) NERVE_IMPL_(Class, Action, Action)



namespace al {
	void initNerve(al::LiveActor *pActor, al::Nerve const*pNerve, int type);
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