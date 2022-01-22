#pragma once

#include "Game/al/LiveActor/LiveActor.h"
#include "Game/al/Util.h"
#include "sead.h"
#include "Game/Actors/Poster/PosterFall.h"

class Poster : public al::LiveActor {
    public:
        Poster(char const*);
        ~Poster();
        void init(al::ActorInitInfo const&);
        void initAfterPlacement();
        bool receiveMsgScreenPoint(al::SensorMsg const*,al::ScreenPointer *,al::ScreenPointTarget *);
        void control();
        void exeWait();
        void exeTouch();
        inline void exeStartWait();
        al::MtxConnector *mMtxConnector; // 108
        int mPosterType; // 110
        PosterFall *mPosterFall; // 118
        bool *mPosterFallDead; // 120

};

namespace
{
    NERVE_HEADER(Poster, StartWait)
    NERVE_HEADER(Poster, Touch)
}