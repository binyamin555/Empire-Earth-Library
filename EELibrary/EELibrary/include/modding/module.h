#pragma once

#include <Windows.h>

#include "modding/.h"

#include "EELibraryExports.h"


MODDING_CORE_NAMESPACE_BEGIN


class Module {
public:
#ifdef EELIBRARY_INTERNAL

	explicit Module()
		: handle(nullptr)
	{
	}

	explicit Module(HMODULE handle)
		: handle(handle)
	{
	}

#endif

	virtual ~Module()
	{
		if (handle != nullptr) {
			FreeLibrary(handle);
			handle = nullptr;
		}
	}

	bool IsLoaded() const
	{
		return handle != nullptr;
	}

	template <typename FnType>
	FnType GetFunction(char const* name) const
	{
		if (handle == nullptr) return nullptr;
		return reinterpret_cast<FnType>(GetProcAddress(handle, name));
	}

	char const* GetPath() const
	{
		if (handle == nullptr) return nullptr;

		static char path[MAX_PATH];
		auto result = GetModuleFileNameA(handle, path, MAX_PATH);
		if (result == 0 || result == MAX_PATH) {
			return nullptr;
		}

		return path;
	}

	bool Load(char const* path)
	{
		if (IsLoaded()) return false;

		handle = LoadLibraryA(path);
		return handle != nullptr;
	}

	bool Unload()
	{
		if (!IsLoaded()) return false;

		auto result = FreeLibrary(handle);
		handle = nullptr;

		return result;
	}

private:
	HMODULE handle;
};


MODDING_CORE_NAMESPACE_END
