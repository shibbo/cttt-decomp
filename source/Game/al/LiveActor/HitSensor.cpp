#include "Game/al/LiveActor/HitSensor.h"
#include "Game/al/LiveActor/SensorHitGroup.h"

namespace al {
    void HitSensor::setFollowPosPtr(const Vec3f *pVec) {
        mFollowPos = pVec, mFollowMtx = nullptr;
    }

    void HitSensor::setFollowMtxPtr(const Matrix34f *pMtx) {
        mFollowPos = nullptr, mFollowMtx = pMtx;
    }
    
    void HitSensor::validate() {
        if (!_39) {
            _39 = 1;

            if (mMaxSensorCount && _38) {
                mHitGroup->add(this);
            }
        }

        mCurSensorCount = 0;
    }

    void HitSensor::invalidate() {
        if (_39) {
            _39 = 0;

            if (mMaxSensorCount && _38) {
                mHitGroup->remove(this);
            }
        }

        mCurSensorCount = 0;
    }

    void HitSensor::validateBySystem() {
        if (!_38) {
            if (mMaxSensorCount && _39) {
                mHitGroup->add(this);
            }

            _38 = 1;
            mCurSensorCount = 0;
        }
    }

    void HitSensor::invalidateBySystem() {
        if (_38) {
            if (mMaxSensorCount && _39) {
                mHitGroup->remove(this);
            }

            _38 = 0;
            mCurSensorCount = 0;
        }
    }

    void HitSensor::addHitSensor(al::HitSensor *pSensor) {
        if (mCurSensorCount < mMaxSensorCount) {
            mSensors[mCurSensorCount] = pSensor;
            mCurSensorCount++;
        }
    }
};