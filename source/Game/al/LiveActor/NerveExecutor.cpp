#include "Game/al/LiveActor/NerveExecutor.h"

namespace al {
    NerveExecutor::NerveExecutor(const char *pName) {
        mNerveKeeper = nullptr;
    }

    NerveExecutor::~NerveExecutor() {
        delete mNerveKeeper;
    }

    void NerveExecutor::initNerve(const Nerve *pNerve, int a2) {
        mNerveKeeper = new NerveKeeper(this, pNerve, a2);
    }

    void NerveExecutor::updateNerve() {
        if (mNerveKeeper) {
            mNerveKeeper->update();
        }
    }
};