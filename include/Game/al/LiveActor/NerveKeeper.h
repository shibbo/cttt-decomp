#pragma once

namespace al {
    class Nerve;
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

        NerveStateCtrl* mStateCtrl;   // _0
        void* _8;
        Nerve* mNextNerve;            // _10
        int mStep;                    // _18
        NerveActionCtrl* _20;
        NerveActionCtrl* mActionCtrl; // _28
    };
};