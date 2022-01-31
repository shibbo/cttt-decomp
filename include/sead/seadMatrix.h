#pragma once

namespace sead {
    template<typename T>
    class Matrix34 {
    public:
        T mMatrix[3][4];    // _0
    };
};

typedef sead::Matrix34<float> Matrix34f;