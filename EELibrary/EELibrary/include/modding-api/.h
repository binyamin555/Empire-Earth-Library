#pragma once


#ifdef EELIBRARY_EXPORTS

#define MODDING_API __declspec(dllexport)

#else

#define MODDING_API __declspec(dllimport)

#endif
