#pragma once

#include "Game/al/Interfaces.h"
#include "Game/al/LiveActor/Nerve.h"

namespace al {
    
    class NerveActionCtrl;
    class NerveStateCtrl;

    class NerveKeeper {
    public:
        NerveKeeper(void *, const Nerve *, int);

        void update();
        void tryChangeNerve();
        void setNerve(const Nerve *pNerve);
        Nerve* getCurrentNerve();
        void initNerveAction(NerveActionCtrl *pActionCtrl);

        //NerveStateCtrl* mStateCtrl;   // _0
        al::IUseNerve* mParent; // _0
        void* _8;
        Nerve* mNextNerve;            // _10
        int mStep;                    // _18
        NerveActionCtrl* _20;
        NerveActionCtrl* mActionCtrl; // _28
    };
};