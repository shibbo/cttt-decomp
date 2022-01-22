#pragma once

#include "Game/al/LiveActor/LiveActor.h"
#include "sead.h"

namespace al {
    struct ActorInitInfo;
    struct PlacementInfo;
    struct MtxConnector;
}



namespace al {
    void initActor(LiveActor *, ActorInitInfo const&);
    void initActorSuffix(LiveActor *, ActorInitInfo const&, char const*);
    void initActorChangeModel(LiveActor *, ActorInitInfo const&);
    void initActorChangeModelSuffix(LiveActor *, ActorInitInfo const&, char const*);
    void initActorWithArchiveName(LiveActor *, ActorInitInfo const&,sead::SafeStringBase<char> const&, char const*);
    void initActorWithArchiveNameWithPlacementInfo(LiveActor *, ActorInitInfo const&,sead::SafeStringBase<char> const&, char const*);
    void initActorWithArchiveNameNoPlacementInfo(LiveActor *, ActorInitInfo const&, sead::SafeStringBase<char> const&, char const*);

    bool tryGetArg(int *,al::ActorInitInfo const&,char const*);
    bool tryGetArg(int *,al::PlacementInfo const&,char const*);
    bool tryGetArg(float *,al::ActorInitInfo const&,char const*);
    bool tryGetArg(float *,al::PlacementInfo const&,char const*);
    bool tryGetArg(bool *,al::ActorInitInfo const&,char const*);
    bool tryGetArg(bool *,al::PlacementInfo const&,char const*);
    bool tryGetArgV2f(sead::Vector2<float> *,al::ActorInitInfo const&,char const*);
    bool tryGetArgV2f(sead::Vector2<float> *,al::PlacementInfo const&,char const*);
    bool tryGetArgV3f(sead::Vector3<float> *,al::ActorInitInfo const&,char const*);
    bool tryGetArgV3f(sead::Vector3<float> *,al::PlacementInfo const&,char const*);
    //bool tryGetArgColor(sead::Color4f *,al::ActorInitInfo const&,char const*);
    //bool tryGetArgColor(sead::Color4f *,al::PlacementInfo const&,char const*);

    MtxConnector *tryCreateMtxConnector(al::LiveActor const*, al::ActorInitInfo const&);
}
