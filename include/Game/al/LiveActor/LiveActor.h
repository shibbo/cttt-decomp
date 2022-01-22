#pragma once

#include "Game/al/Interfaces.h"

namespace al {
    struct ActorInitInfo {

    };

    class SwitchAreaDirector;
    class HitSensor;
    class SensorMsg;
    class ScreenPointer;
    class ScreenPointTarget;
    class ActorPoseKeeperBase;
    class ActorExecuteInfo;
    class ActorActionKeeper;
    class ActorItemKeeper;
    class ActorScoreKeeper;
    class Collider;
    class CollisionParts;
    class ModelKeeper;
    class HitSensorKeeper;
    class ScreenPointKeeper;
    class HitReactionKeeper;
    class RailKeeper;
    class ShadowKeeper;
    class ActorPrePassLightKeeper;
    class ActorOcclusionKeeper;
    class SubActorKeeper;
    class ActorSceneInfo;
    class LiveActorFlag;

    class LiveActor : public IUseNerve, public IUseEffectKeeper, public IUseAudioKeeper, public IUseStageSwitch, public IUseSceneObj, public IUseAreaObj, public IUseCamera, public IUseCollision {
    public:
        LiveActor(const char *);

        virtual NerveKeeper* getNerveKeeper() const;
        virtual ~LiveActor();
        virtual void init(const ActorInitInfo &);
        virtual void initAfterPlacement();
        virtual void registerSwitchAreaDirector(SwitchAreaDirector *);
        virtual void reappear();
        virtual void appear();
        virtual void makeActorAppeared();
        virtual void kill();
        virtual void makeActorDead();
        virtual bool isForcedHidden() const;
        virtual void movement();
        virtual void calcAnim();
        virtual void draw();
        virtual void startClipped();
        virtual void endClipped();
        virtual void attackSensor(HitSensor *, HitSensor *);
        virtual void* getOwnerSensor() const;
        virtual bool receiveMsg(SensorMsg const*, HitSensor *, HitSensor *);
        virtual bool receiveMsgScreenPoint(const SensorMsg *, ScreenPointer *, ScreenPointTarget *);

        virtual const char* getName() const;
        virtual void* getBaseMtx() const;  // should be sead mtx
        virtual EffectKeeper* getEffectKeeper() const;
        virtual AudioKeeper* getAudioKeeper() const;
        virtual StageSwitchKeeper* getStageSwitchKeeper() const;
        virtual SceneObjHolder* getSceneObjHolder() const;
        virtual CollisionDirector* getCollisionDirector() const;
        virtual AreaObjDirector* getAreaObjDirector() const;
        virtual CameraDirector* getCameraDirector() const;
        virtual bool isMovePartDisableStaticTouchEffects() const;
        virtual void initStageSwitchKeeper();
        virtual void initNerveKeeper(al::NerveKeeper *);
        virtual void control();
        virtual void calcAndSetBaseMtx();
        virtual void updateCollider();

        const char* mName;
        ActorPoseKeeperBase* mPoseKeeper;
        ActorExecuteInfo* mExecuteInfo;
        ActorActionKeeper* mActionKeeper;
        ActorItemKeeper* mItemKeeper;
        ActorScoreKeeper* mScoreKeeper;
        Collider* mCollider;
        CollisionParts* mCollisionParts;
        ModelKeeper* mModelKeeper;
        NerveKeeper* mNerveKeeper;
        HitSensorKeeper* mHitSensorKeeper;
        ScreenPointKeeper* mScreenPointKeeper;
        EffectKeeper* mEffectKeeper;
        AudioKeeper* mAudioKeeper;
        HitReactionKeeper* mHitReactionKeeper;
        StageSwitchKeeper* mStageSwitchKeeper;
        RailKeeper* mRailKeeper;
        ShadowKeeper* mShadowKeeper;
        ActorPrePassLightKeeper* mPrePassLightKeeper;
        ActorOcclusionKeeper* mOcclusionKeeper;
        void* _E0;
        SubActorKeeper* mSubActorKeeper;
        void* _F0;
        ActorSceneInfo* mSceneInfo;
        LiveActorFlag* mFlags;
    };
};