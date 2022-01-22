#pragma once

#include "Game/Actors/Poster/Poster.h"

class Poster;

class PosterFall : public al::LiveActor {
    public:
        PosterFall(char const*, Poster const*);
        ~PosterFall();
        void init(al::ActorInitInfo const&);
        void initAfterPlacement();
        void exeFall();
        unsigned char unk[0x118-0x108];
};