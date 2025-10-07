#pragma once

#include <Windows.h>

#include <functional>
#include <thread>
#include <vector>

#include "modding/.h"
#include "modding/mod.h"
#include "modding/module.h"
#include "modding/update-loop.h"

#include "EELibraryExports.h"


MODDING_CORE_NAMESPACE_BEGIN


class ModInstance {
private:
#ifdef EELIBRARY_INTERNAL

	friend class ModManager;

	explicit ModInstance()
		: lifetime(nullptr)
		, module(nullptr)
		, updateLoop(nullptr)
	{
		
	}

	~ModInstance();

#endif

public:

	using ManagedResourceUnloadFunction = std::function<void()>;

	bool IsCurrentlyRunning() const;

	void AddManagedResourceUnloader(ManagedResourceUnloadFunction unload);

	Mod& GetModObject() const { return *lifetime; }

	Module& GetModule() const { return *module; }

#ifdef EELIBRARY_INTERNAL
private:

	void SetModule(Module* mod) { module = mod; }
	void SetModule(Module& mod) { module = &mod; }

	void SetMod(Mod* mod);
	void SetMod(Mod& mod) { SetMod(&mod); }

	void Start();
	void Stop();

	void UnloadManagedResources();
#endif

private:
	Mod* lifetime;
	Module* module;
	UpdateLoop* updateLoop;

	std::vector<ManagedResourceUnloadFunction> managedResourceUnloaders;
};


MODDING_CORE_NAMESPACE_END
