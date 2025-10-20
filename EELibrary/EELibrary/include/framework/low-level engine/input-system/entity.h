#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"


class ISEntity {
public: virtual long Calibrate();
public: IMPORT virtual class UString const& GetName() const;
public: IMPORT virtual long GetNormalizedValue() const;
public: IMPORT virtual long GetValue() const;
public: IMPORT virtual BOOL NeedsCalibration1() const;
public: IMPORT virtual BOOL NeedsCalibration2() const;
public: IMPORT virtual BOOL JustDoublePressed();
public: IMPORT virtual BOOL JustPressed();
public: IMPORT virtual BOOL JustUnpressed();
public: IMPORT virtual unsigned long JustPressedAmount();
public: IMPORT virtual unsigned long JustUnpressedAmount();
public: IMPORT virtual BOOL NeedsCalibration3() const;
public: IMPORT virtual long SetMode1(unsigned long);
public: IMPORT virtual long SetMode2(unsigned long);
public: virtual ~ISEntity();
protected: IMPORT virtual void CheckForDoublePress();
};
