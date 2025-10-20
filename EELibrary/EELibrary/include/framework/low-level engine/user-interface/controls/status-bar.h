#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UIStatusBar : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::StatusBar;

public: UIStatusBar(unsigned long, class GERectangle const&, class UIForm*, unsigned long, unsigned long);
public: UIStatusBar(class UIStatusBar const&);
public: virtual ~UIStatusBar();

public: virtual void ChangeFont(class GEFont*);
public: virtual long CopyData();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
protected: virtual long MouseMove(class GE2DPoint const&);
public: virtual long UpdateKeyboard();
public: virtual void SetLocation(class GE2DPoint const&);

public: long GetMinRange() const;
public: unsigned long GetRange() const;
public: void SetStatusBarOpacity(float);
public: void SetStatusBarColor(class GEColor const&);
public: class UIStatusBar& operator=(class UIStatusBar const&);
public: void SetCurrentRangeValue(long);
public: void SetRange(unsigned long, unsigned long);
public: void SetText(class UWideString const&, class GEFont*);
};
