#pragma once

namespace sead {
    template<typename T>
    class SafeStringBase {
    public:
        SafeStringBase() : mString(&cNullChar) {
            
        }

        virtual ~SafeStringBase() = default;
        virtual void operator=(const SafeStringBase<T> &) = 0;
        virtual void assureTerminationImpl_() const {

        }

        inline const T* cstr() const {
            assureTerminationImpl_();
            return mString;
        }

        const T* mString;   // _8

        static const T cNullChar;
        static const int cMaximumLength = 0x80000;
    };
};

typedef sead::SafeStringBase<char> SafeString;