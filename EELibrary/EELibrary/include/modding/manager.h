#pragma once

#include <filesystem>
#include <vector>

#include "modding/.h"
#include "modding/instance.h"


MODDING_CORE_NAMESPACE_BEGIN


class ModManager {
public:

#ifdef EELIBRARY_INTERNAL

	ModManager();
	~ModManager();

#endif

	ModInstance& LoadMod(std::filesystem::path const& dllPath);
	void UnloadMod(ModInstance& mod);
	void UnloadAllMods();

	bool Manages(ModInstance const& mod) const;

	void StartMod(ModInstance& mod) const;
	void StopMod(ModInstance& mod) const;

private:
	std::vector<ModInstance*> mods;
};


MODDING_CORE_NAMESPACE_END
