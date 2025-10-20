#pragma once

#include "modding/.h"
#include "modding/instance.h"

#include "EELibraryExports.h"


MODDING_CORE_NAMESPACE_BEGIN


extern EELIBRARY_API bool IsModCurrentlyRunning();
extern EELIBRARY_API bool IsModCurrentlyRunning(ModInstance const& mod);

extern EELIBRARY_API ModInstance& GetCurrentlyRunningMod();


extern EELIBRARY_API void SetCurrentlyRunningMod(ModInstance& mod);


MODDING_CORE_NAMESPACE_END
