#include "pch.h"

#include "modding/resource.h"

#include "modding/core.h"


bool MODDING_CORE_NAMESPACE::AddManagedResourceUnloader(ModInstance::ManagedResourceUnloadFunction unload)
{
	if (!IsModCurrentlyRunning()) return false;

	GetCurrentlyRunningMod().AddManagedResourceUnloader(unload);

	return true;
}

void MODDING_CORE_NAMESPACE::RequireAddManagedResourceUnloader(ModInstance::ManagedResourceUnloadFunction unload)
{
	if (!AddManagedResourceUnloader(unload)) {
		throw std::runtime_error("No mod is currently running, cannot add managed resource unloader.");
	}
}
