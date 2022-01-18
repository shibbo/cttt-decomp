#pragma once

namespace al {
    class Nerve;

    class NerveKeeper {
    public:
        NerveKeeper(void *, const Nerve *, int);

        void update();

        unsigned char _0[0x30];
    };
};