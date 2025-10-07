#include "pch.h"

#include "modding/manager.h"

#include "modding/compatibility.h"
#include "modding/lifetime.h"


using namespace MODDING_CORE_NAMESPACE;


ModManager::ModManager()
	: mods()
{

}


ModManager::~ModManager()
{
	if (!mods.empty()) {
		// Log a warning that there are still mods loaded
		// (this should never happen, but just in case)
		// Note: we cannot use Logger here because it might have already been destroyed
		OutputDebugStringA("Warning: ModManager is being destroyed while mods are still loaded!\n");

		UnloadAllMods();
	}
}


ModInstance& ModManager::LoadMod(std::filesystem::path const& dllPath)
{
	ModInstance& modInstance = *new ModInstance();

	HMODULE moduleHandle = LoadLibraryW(dllPath.c_str());
	if (!moduleHandle) {
		throw std::runtime_error("Could not load DLL");
	}

	modInstance.SetModule(new Module(moduleHandle));
	auto& module = modInstance.GetModule();

	auto const moddingLibraryVersion = GetModdingLibraryVersionFor(modInstance);
	if (!moddingLibraryVersion) {

		delete& modInstance;

		throw std::runtime_error("DLL is not a mod (missing " GET_MODDING_LIBRARY_VERSION_STR " function)");
	}

#ifdef EELIBRARY_COMPATIBILITY_CHECK_ENABLED
	// This code will currently not work because compatibility check is not implemented yet

	if (!IsModdingLibraryVersionCompatible(moddingLibraryVersion)) {

		delete& modInstance;

		throw std::runtime_error("DLL is not compatible with this version of Empire Earth Library");
	}
#endif

	auto const createMod = module.GetFunction<Mod * (*)()>(STRINGIFY_MACRO(CREATE_MOD_FUNCTION_NAME));
	if (!createMod) {

		delete& modInstance;

		throw std::runtime_error("DLL is not a mod (missing " STRINGIFY_MACRO(CREATE_MOD_FUNCTION_NAME) " function)");
	}
	auto const destroyMod = module.GetFunction<void(*)(Mod*)>(STRINGIFY_MACRO(DESTROY_MOD_FUNCTION_NAME));
	if (!destroyMod) {

		delete& modInstance;

		throw std::runtime_error("DLL is not a mod (missing " STRINGIFY_MACRO(DESTROY_MOD_FUNCTION_NAME) " function)");
	}

	Mod* const mod = createMod();
	if (!mod) {

		delete& modInstance;

		throw std::runtime_error("Could not create mod instance");
	}

	// Automatically destroy the mod when the instance is unloaded.
	modInstance.AddManagedResourceUnloader(
		[destroyMod, mod]() {
			destroyMod(mod);
		}
	);

	modInstance.SetMod(mod);

	mods.push_back(&modInstance);

	return modInstance;
}

void ModManager::UnloadMod(ModInstance& mod)
{
	auto it = std::find(mods.begin(), mods.end(), &mod);

	if (it == mods.end()) {
		throw std::runtime_error("Mod instance not managed by this ModManager");
	}
	mods.erase(it);

	delete& mod;
}

void ModManager::UnloadAllMods()
{
	for (auto mod : mods)
		delete mod;

	mods.clear();
}

bool ModManager::Manages(ModInstance const& mod) const
{
	auto const it = std::find(mods.begin(), mods.end(), &mod);

	return it != mods.end();
}

void ModManager::StartMod(ModInstance& mod) const
{
	if (!Manages(mod)) {
		throw std::runtime_error("Mod instance not managed by this ModManager");
	}

	mod.Start();
}

void ModManager::StopMod(ModInstance& mod) const
{
	if (!Manages(mod)) {
		throw std::runtime_error("Mod instance not managed by this ModManager");
	}

	mod.Stop();
}
