#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UIScrollBar : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::ScrollBar;

public: UIScrollBar(unsigned long, class GE2DPoint const&, float, unsigned long, class UIForm*, unsigned long, unsigned long);
public: UIScrollBar(class UIScrollBar const&);
public: virtual ~UIScrollBar();

public: virtual long CopyData();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
public: virtual long MouseLButtonDown();
public: virtual long MouseLButtonUp();
public: virtual long MouseMove(class GE2DPoint const&);
public: virtual void SetBgOpacity(float);
public: virtual void SetLocation(class GE2DPoint const&);

public: void DecrementByPageSize();
public: void IncrementByPageSize();
public: void SetCurrentRangeValue(unsigned long);
public: void SetPageSize(unsigned long);
public: void SetRange(unsigned long, unsigned long);
public: class UIScrollBar& operator=(class UIScrollBar const&);
public: void IncrementBy(long);
};
