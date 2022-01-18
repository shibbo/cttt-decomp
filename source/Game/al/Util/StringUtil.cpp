#include "Game/al/Util/StringUtil.h"
#include <cstdio>

namespace al {
    const char* getBaseName(const char *pName) {
        const char* str = strrchr(pName, '/');
        return str ? str + 1 : pName;
    }

    #ifdef NON_MATCHING
    const char* createStringIfInStack(const char *pString) {
        if (isInStack(pString)) {
            size_t length = strlen(pString);
            char* buf = new char[length];
            snprintf(buf, length, "%s", pString);
            return buf;
        }
        else {
            return pString;
        }   
    }
    #endif

    void extractString(char *pDest, const char *pSource, unsigned int start, unsigned int end) {
        strncpy(pDest, pSource, start);
        pDest[start] = 0;
    }

    // al::searchSubString
    // al::searchSubString
    // al::getSubStringUnmatched
    // al::getSubStringUnmatched

    bool tryReplaceString(sead::BufferedSafeStringBase<char> *pString, const char *a2, const char *a3) {
        pString->assureTerminationImpl_();
        return tryReplaceString(pString, pString->mString, a2, a3);
    }

    // al::tryReplaceString
    // al::tryReplaceStringNoRecursive

    /*!
        @brief  Compares two strings to see if they are the same.
        @return  Returns whether the two strings are the same.
    */
    bool isEqualString(const char16_t *pString_0, const char16_t *pString_1) {
        char16_t val;

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

    /*!
        @brief  Compares pString_1 to see if it is contained in pString_0.
        @return  Returns whether or not pString_1 is contained in pString_1.
    */
    bool isEqualSubString(const char *pString_0, const char *pString_1) {
        return strstr(pString_0, pString_1) != 0;
    }

    /*!
        @brief  Compares rString_1 to see if it is contained in rString_0.
        @return  Returns whether or not rString_1 is contained in rString_0.
    */
    bool isEqualSubString(const SafeString &rString_0, const SafeString &rString_1) {
        return strstr(rString_0.cstr(), rString_1.cstr()) != 0;
    }

    /*!
        @brief  Compares pString_0 to see if it starts with pString_1.
        @return  Returns whether or not pString_0 starts with pString_1.
    */
    bool isStartWithString(const char *pString_0, const char *pString_1) {
        if (!*pString_1) {
            return true;
        }

        while (*pString_0 && *pString_0 == *pString_1) {
            ++pString_0;
            ++pString_1;

            if (!*pString_1) {
                return true;
            }
        }

        return false;
    }

    /*!
        @brief  Compares pString_0 to see if it ends with pString_1.
        @return  Returns whether or not pString_0 ends with pString_1.
    */
   bool isEndWithString(const char *pString_0, const char *pString_1) {
       int length_0 = strlen(pString_0);
       int length_1 = strlen(pString_1);

       if (length_0 < length_1) {
           return false;
       }

        // here we get the end of the strings since the second string is longer than the first
       return isEqualString(&pString_0[length_0 - length_1], pString_1);
   }

   // al::isMatchString

    /*!
        @brief  Compares pString_0 to see if it matches pString_1, ignoring cases.
        @return  Returns whether or not pString_0 matches with pString_1, ignoring cases.
    */
   int compareStringIgnoreCase(const char *pString_0, const char *pString_1) {
       return strcasecmp(pString_0, pString_1);
   }

    // al::makeUrlEncodeString
    // al::makeUrlDecodeString

    /*!
        @brief  Copies the string in pSource into the destination pDest.
        @return Nothing.
    */
    void copyString(char *pDest, const char *pSource, unsigned int length) {
        strncpy(pDest, pSource, length);
    }

    // al::copyStringW
    // al::StringTmp dtor
    // al::isInStack

    /*!
        @brief  Compares two strings to see if they are the same.
        @return  Returns whether the two strings are the same.
    */
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

    /*!
        @brief  Compares two SafeStrings to see if they are the same.
        @return  Returns whether the two SafeStrings are the same.
    */
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

    /*!
        @brief  Compares two strings to see if they contain the same casing.
        @return  Returns whether the two strings contain the same casing.
    */
    bool isEqualStringCase(const char *pString_0, const char *pString_1) {
        return strcasecmp(pString_0, pString_1) == 0;
    }

    /*!
        @brief  Compares two SafeStrings to see if they contain the same casing.
        @return  Returns whether the two SafeStrings contain the same casing.
    */
    bool isEqualStringCase(const SafeString &rString_0, const SafeString &rString_1) {
        return strcasecmp(rString_0.cstr(), rString_1.cstr()) == 0;
    }
};