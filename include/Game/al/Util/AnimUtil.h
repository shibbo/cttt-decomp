#pragma once

#include "Game/al/LiveActor/LiveActor.h"

namespace al {
    // actions
    void startAction(al::LiveActor *,char const*);

    // animations
    void startMtpAnimAndSetFrameAndStop(al::LiveActor *,char const*,float);

}