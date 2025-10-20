#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"

#include "./entity.h"
#include "./mouse-axis.h"
#include "./mouse-button.h"

#include "../string/string.h"
#include "../string/wide-string.h"


class ISMouseButtons
{
public:
	bool left;
	bool right;
	bool middle;
	bool other;
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
public: IMPORT BOOL GetShouldUpdate();
public: IMPORT void SetUseBufferedMovement(BOOL);
public: IMPORT ISMouse(class ISMouse const&);
public: IMPORT class ISMouse& operator=(class ISMouse const&);
public: IMPORT virtual ~ISMouse();
private: IMPORT ISMouse(struct IDirectInputDeviceA*, struct HWND__*, class UString const&);
public: virtual unsigned long GetEntityCount() const;
public: virtual unsigned long GetUnk1() const;
public: IMPORT virtual long GetEntity(unsigned long, class ISEntity*&) const;
private: IMPORT void RecomputeCurrentButtonState();
public: IMPORT virtual void Refresh();
public: IMPORT void RefreshXY();
public: IMPORT virtual void Resume();
public: IMPORT virtual long SetMode(unsigned long);
public: IMPORT virtual void Suspend();

public:
	bool isSuspended;
	UString name;
	ISMouseButtons currentButtons;
	ISMouseButtons previousButtons;
	ISMouseDelta currentDelta;
	ISMouseDelta previousDelta;
	union
	{
		struct
		{
			ISMouseAxis* x;
			ISMouseAxis* y;
			ISMouseAxis* z;
			ISMouseButton* left;
			ISMouseButton* right;
			ISMouseButton* middle;
			ISMouseButton* other;
		} *axes;
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
