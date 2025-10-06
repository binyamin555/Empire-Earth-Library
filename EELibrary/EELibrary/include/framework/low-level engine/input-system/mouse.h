#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"

#include "../string/string.h"
#include "../string/wide-string.h"


class ISEntity {
public:
};


class ISMouseAxis
{
public:
	IMPORT virtual UString& GetName();

	UWideString name;
	int32_t* axisValue;
	DWORD axisData;
};


class ISMouseButtons
{
public:
	bool left;
	bool right;
	bool middle;
	bool other;
};


enum class MouseButton 
{
	Left = 0x0,
	Right = 0x1,
	Middle = 0x2,
	Other = 0x3,
};


class ISMouse;


class ISMouseButton {
public:
	IMPORT virtual UString& GetName();

	UWideString name;
	ISMouse* mouse;
	MouseButton button;
	uint32_t lastPressedAt;
	bool isDoublePress;
};


class ISMouseAxes
{
public:
	ISMouseAxis* x;
	ISMouseAxis* y;
	ISMouseAxis* z;
	ISMouseButton* left;
	ISMouseButton* right;
	ISMouseButton* middle;
	ISMouseButton* other;
};


class ISMouseDelta
{
public:
	int32_t x;
	int32_t y;
	int32_t z;
	bool left;
	bool right;
	bool middle;
	bool other;
};


struct IDirectInputDeviceA;


class ISMouse {
public:
	bool isSuspended;
	UString name;
	ISMouseButtons currentButtons;
	ISMouseButtons previousButtons;
	ISMouseDelta currentDelta;
	ISMouseDelta previousDelta;
	union ISMouseEntities
	{
		ISMouseAxes* axes;
		ISEntity(*entities)[7];
	} entities;
	IDirectInputDeviceA* inputDevice;
	ISMouseDelta* currentDeltaPtr;
	void* previousDeltaPtr;
	HWND windowHandle;
	uint32_t entityCount;
	uint32_t unk1;
	bool hasEvents;
	bool useBufferedMovement;
};


extern IMPORT ISMouse* gISMouse;
