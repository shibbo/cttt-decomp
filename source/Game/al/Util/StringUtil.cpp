#include "Game/al/Util/StringUtil.h"
#include <string.h>

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
};