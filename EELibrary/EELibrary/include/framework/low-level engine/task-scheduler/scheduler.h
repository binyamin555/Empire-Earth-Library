#pragma once

#include "framework/low-level engine/.h"

#include "./critical-section.h"


class TSScheduler
{
public:
	IMPORT static long CreateCriticalSection(TSCriticalSection*& criticalSection);

	IMPORT static void DestroyCriticalSection(TSCriticalSection* criticalSection);
};
