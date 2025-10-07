#include "pch.h"

#include "modding/compatibility.h"

#include "EELibrary.h"


using namespace MODDING_CORE_NAMESPACE;


ModdingLibraryVersion MODDING_CORE_NAMESPACE::GetModdingLibraryVersionFor(Module const& mod) {
	auto const getLibVersion = mod.GetFunction<ModdingLibraryVersion(*)()>(GET_MODDING_LIBRARY_VERSION_STR);

	if (getLibVersion == nullptr) {
		return nullptr;
	}

	return getLibVersion();
}

ModdingLibraryVersion MODDING_CORE_NAMESPACE::GetModdingLibraryVersion()
{
	return EELIBRARY_VERSION_STRING;
}

#ifdef EELIBRARY_COMPATIBILITY_CHECK_ENABLED

bool EELIBRARY_API IsModdingLibraryVersionCompatible(ModdingLibraryVersion version)
{
	throw std::runtime_error("Not implemented");
}

#endif
