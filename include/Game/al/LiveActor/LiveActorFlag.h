#pragma once
namespace al {
    class LiveActorFlag {
    public:
        LiveActorFlag();
            bool mIsDead;                       // _0
            bool _1;
            bool _2;
            bool _3;
            bool mIsOnCalcAnim;                 // _4
            bool mIsModelHidden;                // _5
            bool mIsNoCollide;                  // _6
            bool _7;
            bool mIsValidMatCode;               // _8
            bool mIsAreaTarget;                 // _9
            bool mIsOnMoveEffAudioColSensor;    // _A
            bool mIsDying;                      // _B
    };
};