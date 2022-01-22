#include "Game/Actors/Poster/Poster.h"
#include "Game/al/LiveActor/NerveKeeper.h"
#include "Game/al/LiveActor/NerveUtil.h"
#include "Game/al/Util/ActorUtil.h"
#include "Game/al/Util/SensorUtil.h"

#define NONMATCHING



Poster::Poster(char const *pName) : al::LiveActor(pName) {} // TODO

Poster::~Poster() {}

void Poster::init(const al::ActorInitInfo &rInfo) {
    al::initActorWithArchiveName(this, rInfo, "Poster", 0);
    al::initNerve(this, &nrvStartWait, 0);
    al::tryGetArg(&mPosterType, rInfo, "PosterType");
    mPosterFall = new PosterFall("張り紙[落下]", this);
    mPosterFall->init(rInfo); // probably wrong
    mMtxConnector = al::tryCreateMtxConnector(this, rInfo);
    makeActorAppeared();
}



float gDirRange = 50;
float gConnectOffset = -400;

NONMATCHING void Poster::initAfterPlacement() {
    if (!mMtxConnector) return;
    sead::Vector3f *trans = al::getTrans(this);
    sead::Vector3f placement = *trans;
    sead::Vector3f frontDir = sead::Vector3f::zero;
    al::calcFrontDir(&frontDir, this);

    // Everything in this function after this point is non-matching.
    // the if statement at the top also mismatches due to down here
    // too, otherwise this function would be good.
    placement += {frontDir * gDirRange};
    al::attachMtxConnectorToCollision(mMtxConnector, this, placement, {frontDir * gConnectOffset});
}



bool Poster::receiveMsgScreenPoint(al::SensorMsg const*pSensor, al::ScreenPointer *pPointer, al::ScreenPointTarget *pTarget) {
    if (al::isMsgTouchAssistTrigNoPat(pSensor) == false) return false;
    if (al::isNerve(this, &nrvStartWait) == 0) return false;
    al::invalidateScreenPointTargetAll(this);
    al::setNerve(this, &nrvTouch);
    return true;
}



void Poster::control() {
    if (!mMtxConnector) return;
    if (al::isMtxConnectorConnecting(mMtxConnector)) al::connectPoseQT(this, mMtxConnector);
}



inline void Poster::exeStartWait() { // the same as exeWait, but inlined
    if (al::isFirstStep(this) == 0) return;
    al::startAction(this, "Wait");
    al::startMtpAnimAndSetFrameAndStop(this, "Wait", (float)mPosterType);
}



void Poster::exeWait() {
    if (al::isFirstStep(this) == 0) return;
    al::startAction(this, "Wait");
    al::startMtpAnimAndSetFrameAndStop(this, "Wait", (float)mPosterType);
}



void Poster::exeTouch() {

}



namespace {
    NERVE_IMPL(Poster, StartWait) // inlined function, guessed name
    NERVE_IMPL(Poster, Touch)
}