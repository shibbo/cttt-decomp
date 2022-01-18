#pragma once

#include "sead.h"

namespace al {
    bool isEqualString(const char *, const char *);
    bool isEqualString(const SafeString &, const SafeString &);
    bool isEqualStringCase(const char *, const char *);
    bool isEqualStringCase(const SafeString &, const SafeString &);
};