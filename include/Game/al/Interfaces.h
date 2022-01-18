#pragma once

namespace al {
    class AreaObjDirector;
    class AudioKeeper;
    class CameraDirector;
    class CollisionDirector;
    class EffectKeeper;
    class NerveKeeper;
    class SceneObjHolder;
    class StageSwitchKeeper;

    class IUseHioNode {
    public:
        // nothing
    };

    class HioNode : public IUseHioNode {
    public:
        // nothing
    };

    class IUseAudioKeeper {
    public:
        virtual AudioKeeper* getAudioKeeper() const = 0;
    };

    class IUseNerve {
    public:
        virtual NerveKeeper* getNerveKeeper() const = 0;
    };
    
    class IUseEffectKeeper {
    public:
        virtual EffectKeeper* getEffectKeeper() const = 0;
    };

    class IUseSceneObj {
    public:
        virtual SceneObjHolder* getSceneObjHolder() const = 0;
    };

    class IUseName {
    public:
        virtual const char* getName() const = 0;
    };

    class IUseStageSwitch : public virtual IUseName {
    public:
        virtual StageSwitchKeeper* getStageSwitchKeeper() const = 0;
        virtual void initStageSwitchKeeper() = 0;
    };

    class IUseCamera {
    public:
        virtual CameraDirector* getCameraDirector() const = 0;
    };

    class IUseCollision {
    public:
        virtual CollisionDirector* getCollisionDirector() const = 0;
    };

    class IUseAreaObj {
    public:
        virtual AreaObjDirector* getAreaObjDirector() const = 0;
    };
};