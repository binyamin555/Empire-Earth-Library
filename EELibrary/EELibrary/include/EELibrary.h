#pragma once

#include <atomic>
#include <functional>

#include "Logger.h"
#include "Memory.h"
#include "modding/manager.h"

namespace eelib {
class EELibrary {
public:
    EELibrary();
    virtual ~EELibrary();

    BOOL RegisterMainHook(LPVOID pHook);
    BOOL RegisterMainEndHook(LPVOID pHook);

    HMODULE GetSelf() const { return _hself; }
    HMODULE GetHandle() const { return _hinst; }

    void Init(HMODULE hModule);
    void Run();
    void Exit();

    std::unique_ptr<memory::Memory>& GetMemory();
    std::unique_ptr<ee::modding::core::ModManager>& GetModManager();

private:
    std::unique_ptr<memory::Memory> _memory;

    std::unique_ptr<ee::modding::core::ModManager> _modManager;
    const wchar_t* _modPath = L"Mods";

    HMODULE _hinst;
    HMODULE _hself;
#ifdef _DEBUG
    HANDLE _leakLogFile;
#endif // !_DEBUG
};
}

extern EELIBRARY_API std::unique_ptr<eelib::EELibrary> instance;
