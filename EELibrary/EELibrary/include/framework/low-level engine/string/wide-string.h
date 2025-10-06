#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"


class UWideString
{
public:
	IMPORT UWideString();
	IMPORT UWideString(char const* str);
	IMPORT UWideString(unsigned long size);

	IMPORT virtual ~UWideString();

	char* string;
	uint32_t stringLengthInBytes;
	uint32_t stringLength;
	uint32_t allocatedMemorySize;
};

