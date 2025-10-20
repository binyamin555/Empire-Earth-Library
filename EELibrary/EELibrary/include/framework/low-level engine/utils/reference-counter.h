#pragma once

#include <cstdint>

#include "framework/low-level engine/.h"


class UReferenceCounter {
private:
	IMPORT virtual ~UReferenceCounter();

private:
	uint32_t referenceCount;
};
