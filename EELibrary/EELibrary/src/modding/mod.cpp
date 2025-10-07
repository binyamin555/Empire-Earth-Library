#include "pch.h"

#include "modding/mod.h"
#include "modding/update-loop.h"


using namespace MODDING_CORE_NAMESPACE;


Mod::Mod(const char* name)
    : name(name)
{
    
}

Mod::Mod(const char* name, Version const version)
    : name(name)
	, version(version)
{

}

Mod::~Mod()
{

}

const char* Mod::GetName() const
{
    return name.c_str();
}

const Version& Mod::GetVersion() const
{
    return version;
}

bool Mod::IsRunning() const
{
    return running;
}

bool Mod::IsInitialized() const
{
    return initialized;
}

void Mod::Stop()
{
    running = false;
}

void Mod::SetInitialized(bool initialized)
{
    initialized = initialized;
}
