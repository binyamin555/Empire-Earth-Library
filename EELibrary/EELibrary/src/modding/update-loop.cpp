#include "pch.h"

#include "modding/update-loop.h"

#include <thread>

#include "modding/instance.h"


using namespace MODDING_CORE_NAMESPACE;


UpdateLoop::UpdateLoop(UpdateLoopFunction updateLoop)
	: handle(nullptr)
	, updateLoop(updateLoop)
{
}

UpdateLoop::~UpdateLoop()
{
	if (IsRunning() && !Wait(StopTimeout))
		Terminate();
	if (handle) {
		CloseHandle(handle);
		handle = nullptr;
	}
}

void UpdateLoop::Start()
{
	if (IsRunning()) return;

	handle = CreateThread(
		nullptr,
		0,
		[](LPVOID param) -> DWORD {
			auto const updateLoop = static_cast<UpdateLoopFunction*>(param);
			try {
				(*updateLoop)();
			}
			catch (...) {
				// We must not let exceptions escape the thread function.
				// Just silently ignore them for now.
			}
			return 0;
		},
		&updateLoop,
		0,
		nullptr
	);
}

void UpdateLoop::Terminate()
{
	if (!handle) return;

	TerminateThread(handle, 0);	
}

bool UpdateLoop::Wait(DWORD timeout) const
{
	return WaitForSingleObject(handle, timeout) != WAIT_TIMEOUT;
}

bool UpdateLoop::IsRunning() const
{
	if (!handle) return false;

	DWORD exitCode;

	if (!GetExitCodeThread(handle, &exitCode))
		throw std::runtime_error("GetExitCodeThread failed");

	return exitCode == STILL_ACTIVE;
}

