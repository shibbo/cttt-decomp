#pragma once

#include "sead.h"

namespace al {
    class LiveActor;
    class SensorHitGroup;

    class HitSensor {
    public:

        void setFollowPosPtr(const Vec3f *);
        void setFollowMtxPtr(const Matrix34f *);
        void validate();
        void invalidate();
        void validateBySystem();
        void invalidateBySystem();

        void update();
        void addHitSensor(al::HitSensor *);

        al::LiveActor* mHostActor;  // _0
        unsigned int _8;
        float _C;
        float _10;
        float _14;
        float _18;
        unsigned short mMaxSensorCount;     // _1C
        unsigned short mCurSensorCount;     // _1E
        al::HitSensor** mSensors;           // _20
        long _28;
        SensorHitGroup* mHitGroup;          // _30
        unsigned char _38;
        unsigned char _39;
        unsigned char _3A;
        unsigned char _3B;
        int _3C;
        long _40;
        const Vec3f* mFollowPos;            // _48
        const Matrix34f* mFollowMtx;        // _50
        float _58;
        float _5C;
        float _60;
    };
};