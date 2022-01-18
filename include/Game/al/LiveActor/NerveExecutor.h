#pragma once

#include "Game/al/Interfaces.h"
#include "Game/al/LiveActor/NerveKeeper.h"

namespace al {
    class NerveExecutor : public al::IUseNerve, al::HioNode {
    public:
        NerveExecutor(const char *);

        virtual NerveKeeper* getNerveKeeper() const {
            return mNerveKeeper;
        }

        virtual ~NerveExecutor();

        void initNerve(const al::Nerve *, int);
        void updateNerve();

        NerveKeeper* mNerveKeeper;  // _8
    };
};