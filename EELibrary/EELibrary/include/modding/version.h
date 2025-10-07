#pragma once

#include "modding/.h"

#include "EELibraryExports.h"


MODDING_CORE_NAMESPACE_BEGIN


class EELIBRARY_API Version {
public:
    using Segment = int;

    Version();
    explicit Version(const char* version);
    Version(const Version& version);
    Version(Segment major, Segment minor, Segment patch);
    virtual ~Version();

    Version& operator=(const Version& version);
    bool operator==(const Version& version) const;
    bool operator>(const Version& version) const;
    bool operator<(const Version& version) const;
    bool operator>=(const Version& version) const;
    bool operator<=(const Version& version) const;
    bool operator!=(const Version& version) const;

    const char* GetString() const;

    Segment GetMajor() const;
    Segment GetMinor() const;
    Segment GetPatch() const;

private:
    Segment major;
    Segment minor;
    Segment patch;
};


MODDING_CORE_NAMESPACE_END
