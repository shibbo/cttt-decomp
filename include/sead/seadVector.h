#pragma once

namespace sead {
    template<typename T>
    class Vector3 {
    public:
        T x;    // _0
        T y;    // _4
        T z;    // _8
    };
};

typedef sead::Vector3<float> Vec3f;