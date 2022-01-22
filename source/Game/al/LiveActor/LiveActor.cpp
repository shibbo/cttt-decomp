#include "Game/al/LiveActor/LiveActor.h"
#include <string.h>

namespace al {
    LiveActor::LiveActor(const char *pName) : mName(pName) {
        memset(&mPoseKeeper, 0, 0xC0);
        mFlags = new LiveActorFlag();
    }

    /*LiveActor::~LiveActor() {
        delete mFlags;
        delete mStageSwitchKeeper;
        delete mScreenPointKeeper;
        delete mHitSensorKeeper;
        delete mModelKeeper;
        delete mModelKeeper;
        delete mCollider;
        delete mScoreKeeper;
        delete mItemKeeper;
    }*/

    void LiveActor::init(const ActorInitInfo &rInfo) {

    }
};