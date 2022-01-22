#include "Game/al/LiveActor/LiveActor.h"
#include "Game/al/LiveActor/LiveActorFlag.h"
#include <string.h>

namespace al {
    LiveActor::LiveActor(const char *pName) : mName(pName) {
        mPoseKeeper = nullptr;
        mExecuteInfo = nullptr;
        mActionKeeper = nullptr;
        mItemKeeper = nullptr;
        mScoreKeeper = nullptr;
        mCollider = nullptr;
        mCollisionParts = nullptr;
        mModelKeeper = nullptr;
        mNerveKeeper = nullptr;
        mHitSensorKeeper = nullptr;
        mScreenPointKeeper = nullptr;
        mEffectKeeper = nullptr;
        mAudioKeeper = nullptr;
        mHitReactionKeeper = nullptr;
        mStageSwitchKeeper = nullptr;
        mRailKeeper = nullptr;
        mShadowKeeper = nullptr;
        mPrePassLightKeeper = nullptr;
        mOcclusionKeeper = nullptr;
        _E0 = nullptr;
        mSubActorKeeper = nullptr;
        _F0 = nullptr;
        mSceneInfo = nullptr;
        mFlags = nullptr;

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