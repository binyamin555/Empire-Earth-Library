#include "pch.h"

#include "modding/version.h"


using namespace MODDING_CORE_NAMESPACE;


Version::Version()
	: Version(0, 0, 0)
{
    
}

Version::~Version()
{
}

Version::Version(const char* version)
{
    sscanf_s(version, "%d.%d.%d", &major, &minor, &patch);
}

Version::Version(const Version& version)
	: Version(version.major, version.minor, version.patch)
{
    
}

Version::Version(Segment major, Segment minor, Segment patch)
    : major(major)
    , minor(minor)
	, patch(patch)
{
    
}

Version& Version::operator=(const Version& version)
{
	major = version.major;
	minor = version.minor;
	patch = version.patch;
    return *this;
}

bool Version::operator==(const Version& version) const
{
    return major == version.major && minor == version.minor && patch == version.patch;
}

bool Version::operator>(const Version& version) const
{
    return major > version.major || (major == version.major && minor > version.minor) || (major == version.major && minor == version.minor && patch > version.patch);
}

bool Version::operator<(const Version& version) const
{
    return !(version > *this);
}

bool Version::operator>=(const Version& version) const
{
    return *this > version || *this == version;
}

bool Version::operator<=(const Version& version) const
{
    return *this < version || *this == version;
}

bool Version::operator!=(const Version& version) const
{
    return !(*this == version);
}

const char* Version::GetString() const
{
    static char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d.%d.%d", major, minor, patch);
    return buffer;
}

Version::Segment Version::GetMajor() const
{
    return major;
}

Version::Segment Version::GetMinor() const
{
    return minor;
}

Version::Segment Version::GetPatch() const
{
    return patch;
}
