#pragma once

#include "modding/.h"
#include "modding/instance.h"

#include "EELibraryExports.h"


MODDING_CORE_NAMESPACE_BEGIN


bool EELIBRARY_API AddManagedResourceUnloader(ModInstance::ManagedResourceUnloadFunction unload);

void EELIBRARY_API RequireAddManagedResourceUnloader(ModInstance::ManagedResourceUnloadFunction unload);


MODDING_CORE_NAMESPACE_END
