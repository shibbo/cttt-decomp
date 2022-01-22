#pragma once

namespace sead {
    template<typename T>
    class SafeStringBase {
    public:
        SafeStringBase() : mString(&cNullChar) {}
        SafeStringBase(const T* str) : mString(str)
        {
            //SEAD_ASSERT_MSG(str != nullptr, "str must not be nullptr.");
        }

        SafeStringBase(const SafeStringBase& other) = default;
        virtual ~SafeStringBase() = default;
        virtual SafeStringBase& operator=(const SafeStringBase& other);
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

    template<typename T>
    class BufferedSafeStringBase : public SafeStringBase<T> {
    public:
        BufferedSafeStringBase(T *pBuffer, int size) : SafeStringBase<T>(pBuffer) {
            mBufferSize = size;

            if (size <= 0) {
                this->mString = nullptr;
                this->mBufferSize = 0;
            }
            else {
                assureTerminationImpl_();
            }
        }

        virtual ~BufferedSafeStringBase() override = default;
        BufferedSafeStringBase<T>& operator=(const SafeStringBase<T> &) override;
        virtual void assureTerminationImpl_() const override;

        int mBufferSize;    // _C
    };
};

typedef sead::SafeStringBase<char> SafeString;