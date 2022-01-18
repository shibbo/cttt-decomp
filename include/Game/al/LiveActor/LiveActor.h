#pragma once

#include "Game/al/Interfaces.h"

namespace al {
    struct ActorInitInfo {

    };

    class SwitchAreaDirector;

    class LiveActor : public IUseNerve, public IUseEffectKeeper, public IUseAudioKeeper, public IUseStageSwitch, public IUseSceneObj, public IUseAreaObj, public IUseCamera, public IUseCollision {
    public:
        // good luck to the poor soul that does this one
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

        // todo -- finish me

        virtual const char* getName() const;
        virtual EffectKeeper* getEffectKeeper() const;
        virtual AudioKeeper* getAudioKeeper() const;
        virtual StageSwitchKeeper* getStageSwitchKeeper() const;
        virtual SceneObjHolder* getSceneObjHolder() const;
        virtual CollisionDirector* getCollisionDirector() const;
        virtual AreaObjDirector* getAreaObjDirector() const;
        virtual CameraDirector* getCameraDirector() const;
        virtual bool isMovePartDisableStaticTouchEffects() const;
        virtual void initStageSwitchKeeper();
        virtual void control();
        virtual void calcAndSetBaseMtx();
        virtual void updateCollider();
    };
};