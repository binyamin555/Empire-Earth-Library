#include "pch.h"

#include "modding/instance.h"

#include "modding/core.h"


using namespace MODDING_CORE_NAMESPACE;


ModInstance::~ModInstance()
{
	if (lifetime) {
		if (lifetime->IsRunning())
			Stop();
	}

	if (updateLoop) {
		if (updateLoop->IsRunning())
			updateLoop->Terminate();

		delete updateLoop;
		updateLoop = nullptr;
	}

	UnloadManagedResources();

	if (module) {
		delete module;
		module = nullptr;
	}
}

bool ModInstance::IsCurrentlyRunning() const
{
    return IsModCurrentlyRunning(*this);
}

void ModInstance::AddManagedResourceUnloader(ManagedResourceUnloadFunction unload)
{
	managedResourceUnloaders.push_back(unload);
}

void ModInstance::SetMod(Mod* mod)
{
	if (!mod) throw std::invalid_argument("mod is null");
	if (lifetime) throw std::runtime_error("mod is already set");

	lifetime = mod;
	updateLoop = new UpdateLoop(
		[this, mod]() {
			while (mod->IsRunning()) {
				auto& currentMod = GetCurrentlyRunningMod();

				SetCurrentlyRunningMod(*this);

				// TODO: We might want to actually allow for other kinds of commands.
				auto const timeToYield = mod->OnUpdate();

				SetCurrentlyRunningMod(currentMod);

				Sleep(timeToYield);
			}
		}
	);
}

void ModInstance::Start()
{
	if (!lifetime) throw std::runtime_error("mod is not set");

	if (lifetime->IsInitialized() || lifetime->IsRunning())
		throw std::runtime_error("mod is already started or not initialized");

	if (!updateLoop) throw std::runtime_error("update loop is not set");

	auto& previousMod = GetCurrentlyRunningMod();
	SetCurrentlyRunningMod(*this);

	if (lifetime->OnStart())
	{
		lifetime->running = true;
		updateLoop->Start();
	}

	SetCurrentlyRunningMod(previousMod);
}

void ModInstance::Stop()
{
	if (!lifetime) throw std::runtime_error("mod is not set");
	if (!updateLoop) throw std::runtime_error("update loop is not set");

	lifetime->Stop();
	if (updateLoop->IsRunning() && !updateLoop->Wait(UpdateLoop::StopTimeout))
		updateLoop->Terminate();

	auto& previousMod = GetCurrentlyRunningMod();
	SetCurrentlyRunningMod(*this);

	lifetime->OnStop();

	SetCurrentlyRunningMod(previousMod);
}

void ModInstance::UnloadManagedResources()
{
	for (auto& unloader : managedResourceUnloaders) {
		unloader();
	}
	managedResourceUnloaders.clear();
}
