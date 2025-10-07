#pragma once

#include "modding/.h"
#include "modding/mod.h"

#include "EELibraryExports.h"


#define CREATE_MOD_FUNCTION_NAME CreateMod
#define DESTROY_MOD_FUNCTION_NAME DestroyMod


#ifndef EELIBRARY_INTERNAL

#define CREATE_MOD extern "C" __declspec(dllexport) MODDING_CORE_NAMESPACE::Mod* CREATE_MOD_FUNCTION_NAME

#define DESTROY_MOD extern "C" __declspec(dllexport) void DESTROY_MOD_FUNCTION_NAME

#endif
