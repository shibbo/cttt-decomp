#include "Game/al/Util/StringUtil.h"
#include <strings.h>

namespace al {
    bool isEqualString(const char *pString_0, const char *pString_1) {
        char val;

        while (true) {
            val = *pString_0;

            if (val != *pString_1) {
                break;
            }

            ++pString_1;
            ++pString_0;

            if (!val) {
                return true;
            }
        }

        return false;
    }

    bool isEqualString(const SafeString &rString_0, const SafeString &rString_1) {
        const char* str_0 = rString_0.cstr();
        const char* str_1 = rString_1.cstr();

        char val;

        while (true) {
            val = *str_0;

            if (val != *str_1) {
                break;
            }

            ++str_1;
            ++str_0;

            if (!val) {
                return true;
            }
        }

        return false;
    }

    bool isEqualStringCase(const char *pString_0, const char *pString_1) {
        return strcasecmp(pString_0, pString_1) == 0;
    }

    bool isEqualStringCase(const SafeString &rString_0, const SafeString &rString_1) {
        return strcasecmp(rString_0.cstr(), rString_1.cstr()) == 0;
    }
};