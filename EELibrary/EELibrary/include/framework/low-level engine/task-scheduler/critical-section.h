#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"


class TSCriticalSection
{
public:
	IMPORT void Enter();
	IMPORT void Leave();

private:
	IMPORT TSCriticalSection();
	IMPORT ~TSCriticalSection();

	CRITICAL_SECTION criticalSection;
	DWORD firstVisitorThreadId;
	uint32_t visitorCount;
};
