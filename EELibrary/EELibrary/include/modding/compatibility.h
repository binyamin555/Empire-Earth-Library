#pragma once

#include "modding/.h"
#include "modding/instance.h"
#include "modding/module.h"

#include "EELibraryExports.h"


#define GET_MODDING_LIBRARY_VERSION GetModdingLibraryVersion
#define GET_MODDING_LIBRARY_VERSION_STR STRINGIFY_MACRO(GET_MODDING_LIBRARY_VERSION)


MODDING_CORE_NAMESPACE_BEGIN


using ModdingLibraryVersion = char const*;


#ifdef EELIBRARY_COMPATIBILITY_CHECK_ENABLED

bool EELIBRARY_API IsModdingLibraryVersionCompatible(ModdingLibraryVersion version);

#endif


extern EELIBRARY_API ModdingLibraryVersion GetModdingLibraryVersion();


extern EELIBRARY_API ModdingLibraryVersion GetModdingLibraryVersionFor(Module const& mod);


ModdingLibraryVersion inline GetModdingLibraryVersionFor(ModInstance const& mod) {
	return GetModdingLibraryVersionFor(mod.GetModule());
}


MODDING_CORE_NAMESPACE_END


#ifdef EE_MOD_CONFIG

#include "EELibrary.h"

extern "C" __declspec(dllexport) MODDING_CORE_NAMESPACE::ModdingLibraryVersion GET_MODDING_LIBRARY_VERSION() {
	return EELIBRARY_VERSION_STRING;
}

#endif
