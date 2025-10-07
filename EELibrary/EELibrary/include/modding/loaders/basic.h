#pragma once

#include "modding/.h"
#include "modding/loader.h"


MODDING_LOADER_NAMESPACE_BEGIN 


class BasicLoader : public Loader {
public:
	void Load(Path modFolder) override;
};


MODDING_LOADER_NAMESPACE_END
