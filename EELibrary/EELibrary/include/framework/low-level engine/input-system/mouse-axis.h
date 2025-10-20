#pragma once

#include "framework/low-level engine/.h"

#include "framework/low-level engine/string/wide-string.h"

#include "./entity.h"


class ISMouseAxis : public ISEntity {
private:
	UWideString name;
	int32_t *axisValue;
	DWORD axisData;
};