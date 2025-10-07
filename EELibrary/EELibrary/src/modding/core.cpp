#include "pch.h"

#include <thread>

#include "modding/core.h"


using namespace MODDING_CORE_NAMESPACE;


static thread_local ModInstance* currentlyRunningMod = nullptr;


bool MODDING_CORE_NAMESPACE::IsModCurrentlyRunning()
{
	return currentlyRunningMod != nullptr;
}

bool MODDING_CORE_NAMESPACE::IsModCurrentlyRunning(ModInstance const& mod)
{
	return currentlyRunningMod == &mod;
}

ModInstance& MODDING_CORE_NAMESPACE::GetCurrentlyRunningMod()
{
	return *currentlyRunningMod;
}

void MODDING_CORE_NAMESPACE::SetCurrentlyRunningMod(ModInstance& mod)
{
	currentlyRunningMod = &mod;
}
