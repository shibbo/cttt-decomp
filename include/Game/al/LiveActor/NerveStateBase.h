#pragma once

#include "Game/al/LiveActor/NerveExecutor.h"

namespace al {
    class LiveActor;

    class NerveStateBase : public NerveExecutor {
    public:
        NerveStateBase(const char *);

        virtual ~NerveStateBase();
        virtual void init();
        virtual void appear();
        virtual void kill();
        virtual void update();
        virtual void control();

        bool mIsDead;   // _10
    };

    class ActorStateBase : public NerveExecutor {
    public:
        ActorStateBase(const char *, LiveActor *);

        virtual ~ActorStateBase();
        virtual void init();
        virtual void appear();
        virtual void kill();
        virtual void update();
        virtual void control();

        bool mIsDead;           // _10
        LiveActor* mHostActor;  // _18
    };
};