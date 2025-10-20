#pragma once

#include "framework/low-level engine/.h"

#include "framework/low-level engine/string/wide-string.h"

#include "./entity.h"


class ISMouseButton : public ISEntity {
public:
	enum class Button : uint32_t
	{
		Left = 0x0,
		Right = 0x1,
		Middle = 0x2,
		Other = 0x3,
	};

private:
	UWideString name;
	class ISMouse* mouse;
	Button button;
	uint32_t lastPressedAt;
	bool isDoublePress;
};