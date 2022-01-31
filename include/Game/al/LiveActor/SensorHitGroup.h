#pragma once

namespace al {
    class HitSensor;

    class SensorHitGroup {
    public:
        SensorHitGroup(int, const char *);

        void add(al::HitSensor *);
        void remove(al::HitSensor *);
        al::HitSensor* getSensor(int) const;
        void clear() const;

        int mMaxSensorCount;        // _0
        int mSensorCount;           // _4
        al::HitSensor** mSensors;   // _8
    };
};