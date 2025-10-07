#include "pch.h"

#include "EELibrary.h"
#include <exceptions/ModManagerException.h>
#include <exceptions/core/CoreInitException.h>
#include <sstream>

#include "Logger.h"
#include "Memory.h"

#include "modding/loaders/basic.h"
#include "utils/utils.h"

using namespace eelib;

int LockLibraryIntoProcessMem(HMODULE dllHandle, HMODULE* localDllHandle)
{
    if (localDllHandle == NULL)
        return ERROR_INVALID_PARAMETER;
    *localDllHandle = NULL;
    TCHAR DllPath[MAX_PATH];
    if (GetModuleFileName(dllHandle, DllPath, MAX_PATH) == NULL)
        return GetLastError();
    *localDllHandle = LoadLibrary(DllPath);
    if (*localDllHandle == NULL)
        return GetLastError();
    return ERROR_SUCCESS;
}

EELibrary::EELibrary()
{
    Logger::Init("Library");

    Logger::Info("============================================================");
    Logger::Info("Initialized EELibrary v{}.{}.{}", EELIBRARY_VERSION_MAJOR, EELIBRARY_VERSION_MINOR, EELIBRARY_VERSION_PATCH);
    Logger::Info("Created by: EnergyCube");
    Logger::Info("============================================================");

#ifdef _DEBUG
    Logger::Trace("Initializing Memory Leak Detection...");

    //_leakLogFile = CreateFile(L"__leak.txt", GENERIC_WRITE,
    //    FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
    //    FILE_ATTRIBUTE_NORMAL, NULL);

    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_DELAY_FREE_MEM_DF);

    //_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    //_CrtSetReportFile(_CRT_ERROR, _leakLogFile);
    //_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    //_CrtSetReportFile(_CRT_WARN, _leakLogFile);
    //_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
    //_CrtSetReportFile(_CRT_ASSERT, _leakLogFile);

    Logger::Trace("Initialized Memory Leak Detection");
#endif // _DEBUG

    Logger::Trace("Initializing Memory...");
    _memory = std::make_unique<eelib::memory::Memory>();
    _memory->Initialize();
    Logger::Trace("Initialized Memory");

    Logger::Trace("Initializing ModManager...");
    _modManager = std::make_unique<ee::modding::core::ModManager>();
    Logger::Trace("Initialized ModManager");
}

EELibrary::~EELibrary()
{
    Logger::Trace("Uninitializing Memory...");
    _memory->Uninitialize();
    _memory.reset();
    Logger::Trace("Uninitialized Memory");

    Logger::Trace("Uninitializing Logger...");
    Logger::Uninit();

#ifdef _DEBUG
    //_CrtCheckMemory();
    //_CrtDumpMemoryLeaks();
    CloseHandle(_leakLogFile);
#endif // _DEBUG
}

void EELibrary::Init(HMODULE hModule)
{
    if (_hinst != NULL)
        throw CoreInitException("EELibrary already initialized");
    _hinst = hModule;
    if (LockLibraryIntoProcessMem(_hinst, &_hself) != ERROR_SUCCESS)
        throw CoreInitException("Failed to lock library into process memory");

	ee::modding::loader::Loader& loader = *new ee::modding::loader::BasicLoader();

    if (!FolderExist(_modPath))
        return;

	loader.Load(_modPath);
}

void EELibrary::Run()
{
}

void EELibrary::Exit()
{
    _modManager->UnloadAllMods();
    _modManager.reset();
    // We don't uninitalize Memory here because we need it
    // to call the original LLE UShutdown function
    // We will destroy the object after that function is called
    // which is totally fine because everything is already unloaded
}

std::unique_ptr<memory::Memory>& EELibrary::GetMemory()
{
    return _memory;
}

std::unique_ptr<ee::modding::core::ModManager>& eelib::EELibrary::GetModManager()
{
    return _modManager;
}

BOOL EELibrary::RegisterMainHook(LPVOID pHook)
{
    Logger::Trace("Registering main hook");
    if (_memory->HookFunction(_memory->Game_StartAddr, pHook, (LPVOID*)&_memory->Game_StartOrg) != EELIBRARY_OK)
        return FALSE;
    Logger::Trace("Registered main hook");
    return TRUE;
}

BOOL EELibrary::RegisterMainEndHook(LPVOID pHook)
{
    Logger::Trace("Registering main end hook");
    if (_memory->HookFunction(_memory->LLE_UShutdownAddr, pHook, (LPVOID*)&_memory->LLE_UShutdownOrg) != EELIBRARY_OK)
        return FALSE;
    Logger::Trace("Registered main end hook");
    return TRUE;
}

std::unique_ptr<eelib::EELibrary> instance;
