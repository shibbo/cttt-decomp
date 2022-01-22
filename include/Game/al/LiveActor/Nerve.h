#pragma once

#include "Game/al/LiveActor/NerveKeeper.h"

namespace al {
    class Nerve {
        public:
            virtual void execute(NerveKeeper *) = 0;
            virtual void executeOnEnd(NerveKeeper *) const;
    };
}