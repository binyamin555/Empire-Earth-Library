/*

        You should not need to modify anything in this file, 
		except the include of your mod main header file.

        Just replace "ModTemplate.h" with your mod main header file.
        Also replace "MOD_CLASS_NAME" with the name of your mod main class.
*/

#include "pch.h"

#include "ModTemplate.h" // Replace with your mod main header

#include <cassert>


// ------------- Mod Manifest -------------

#include "modding/lifetime.h"

CREATE_MOD() {
    return new MOD_CLASS_NAME();
}

DESTROY_MOD(MODDING_CORE_NAMESPACE::Mod* mod) {
    delete mod;
}

// ----------------------------------------


/*
    Historically, Empire Earth mods DLLs took advantage of DllMain
    to launch a thread and modify the game during execution.
    However you don't have to do this, as Empire Earth Library takes
    care of this step and calls your OnInit, OnStart and OnStop functions.
    It is therefore extremely important not to put anything here.
*/
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
