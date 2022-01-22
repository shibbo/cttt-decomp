#include "Game/al/LiveActor/LiveActor.h"
#include "Game/al/LiveActor/LiveActorFlag.h"
#include <string.h>

namespace al {
    LiveActor::LiveActor(const char *pName) {
        mName = pName;
        mFlags = new LiveActorFlag();
    }

    /*LiveActor::~LiveActor() {
        delete mFlags;
        delete mStageSwitchKeeper;
        delete mScreenPointKeeper;
        delete mHitSensorKeeper;
        delete mModelKeeper;
        delete mCollider;
        delete mScoreKeeper;
        delete mItemKeeper;
    }*/

    void LiveActor::init(const ActorInitInfo &rInfo) {

    }
};