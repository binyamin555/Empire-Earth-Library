#pragma once

#include "modding/.h"


#define MODDING_LOADER_NAMESPACE MODDING_NAMESPACE::loader

#define MODDING_LOADER_NAMESPACE_BEGIN namespace MODDING_LOADER_NAMESPACE {
#define MODDING_LOADER_NAMESPACE_END }


MODDING_LOADER_NAMESPACE_BEGIN


using Path = wchar_t const*;


class Loader {
public:
	virtual void Load(Path modFolder) = 0;
};


MODDING_LOADER_NAMESPACE_END
