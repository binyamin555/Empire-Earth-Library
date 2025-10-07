#pragma once

#include <Windows.h>

#include <functional>

#include "modding/.h"

#include "EELibraryExports.h"


MODDING_CORE_NAMESPACE_BEGIN


class UpdateLoop {
public:
	using UpdateLoopFunction = std::function<void()>;
	static constexpr DWORD StopTimeout = 5000; // milliseconds

#ifdef EELIBRARY_INTERNAL
private:
	friend class ModInstance;

	UpdateLoop(UpdateLoopFunction updateLoop);
	~UpdateLoop();

	void Start();

	void Terminate();

	bool Wait(DWORD timeout) const;

	bool IsRunning() const;

#endif

private:
	HANDLE handle;
	UpdateLoopFunction updateLoop;
};


MODDING_CORE_NAMESPACE_END
