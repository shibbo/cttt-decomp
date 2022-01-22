#pragma once

#include "Game/al/LiveActor/LiveActor.h"
#include "sead.h"

namespace al {
    struct MtxConnector;
}

namespace al {
    sead::Vector3f *getTrans(al::LiveActor const*);

    sead::Vector3f *calcFrontDir(sead::Vector3<float> *,al::LiveActor const*);

    void invalidateScreenPointTargetAll(al::LiveActor *);

    void connectPoseQT(al::LiveActor *,al::MtxConnector const*);
    bool isMtxConnectorConnecting(al::MtxConnector const*);
    void attachMtxConnectorToCollision(al::MtxConnector *,al::LiveActor const*,sead::Vector3<float> const&,sead::Vector3<float> const&);
}