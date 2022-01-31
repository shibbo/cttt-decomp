#include "Game/al/LiveActor/SensorHitGroup.h"
#include "Game/al/LiveActor/HitSensor.h"

namespace al {
    SensorHitGroup::SensorHitGroup(int maxCount, const char *pUnused) {
        mMaxSensorCount = maxCount;
        mSensorCount = 0;
        mSensors = new al::HitSensor*[maxCount];

        if (maxCount >= 1) {
            for (int i = 0; i < mMaxSensorCount; i++) {
                mSensors[i] = nullptr;
            }
        }
    }

    void SensorHitGroup::add(al::HitSensor *pSensor) {
        mSensors[mSensorCount] = pSensor;
        mSensorCount++;
    }

    al::HitSensor* SensorHitGroup::getSensor(int idx) const {
        return mSensors[idx];
    }

    void SensorHitGroup::clear() const {
        if (mSensorCount >= 1) {
            for (int i = 0; i < mSensorCount; i++) {
                mSensors[i]->mCurSensorCount = 0;
            }
        }
    }
};