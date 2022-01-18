#pragma once

#include "sead.h"

#include <nn/nn_Macro.h>
#include <cstddef>
#include <cstring>
#include <strings.h>

namespace al {
    const char* getBaseName(const char *);
    const char* createStringIfInStack(const char *);

    void extractString(char *, const char *, unsigned int, unsigned int);

    bool tryReplaceString(sead::BufferedSafeStringBase<char> *, const char *, const char *);
    bool tryReplaceString(sead::BufferedSafeStringBase<char> *, const char *, const char *, const char *);

    bool isEqualString(const char16_t *, const char16_t *);
    bool isEqualSubString(const char *, const char *);
    bool isEqualSubString(const SafeString &, const SafeString &);
    bool isStartWithString(const char *, const char *);
    bool isEndWithString(const char *, const char *);

    int compareStringIgnoreCase(const char *, const char *);

    void copyString(char *, const char *, unsigned int);

    bool isInStack(const void *);

    bool isEqualString(const char *, const char *) NN_NOINLINE;
    bool isEqualString(const SafeString &, const SafeString &);
    bool isEqualStringCase(const char *, const char *);
    bool isEqualStringCase(const SafeString &, const SafeString &);
};