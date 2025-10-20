#pragma once

#include <modding/mod.h>

#define EE_MOD ModTemplate
#define MOD_NAME "Mod Template"

#define MOD_CLASS_NAME EE_MOD

/*
        Sleep is required to prevent the thread from using too much CPU
        Feel free to change the sleep time to your liking (in milliseconds)
        But don't set it too low, or you will get a lot of CPU usage :V

        When the mod get unloaded the Library give 4s to the thread to exit
*/
#define MOD_UPDATE_INTERVAL 10

#define MOD_VERSION_MAJOR 1
#define MOD_VERSION_MINOR 0
#define MOD_VERSION_PATCH 0

#define MOD_VERSION_STRING STRINGIFY(MOD_VERSION_MAJOR) "." STRINGIFY(MOD_VERSION_MINOR) "." STRINGIFY(MOD_VERSION_PATCH

#ifdef MODTEMPLATE_EXPORTS
#define MODTEMPLATE_API __declspec(dllexport)
#else
#define MODTEMPLATE_API __declspec(dllimport)
#endif

/*
        You should not need to modify anything below this line.
        =======================================================
*/

#define MOD_VERSION ((MOD_VERSION_MAJOR << 16) | (MOD_VERSION_MINOR << 8) | MOD_VERSION_PATCH)
#if MOD_VERSION_MAJOR > 255 || MOD_VERSION_MINOR > 255 || MOD_VERSION_PATCH > 255
#error "MOD_VERSION_MAJOR, MOD_VERSION_MINOR and MOD_VERSION_PATCH must be less than 256."
#endif
