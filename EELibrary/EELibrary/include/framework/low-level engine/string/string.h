#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"


class UString
{
public:
	IMPORT UString();
	IMPORT UString(char const* str);

	IMPORT virtual ~UString();

	char* cString;
	uint32_t stringLength;
	uint32_t allocatedMemorySize;
};

