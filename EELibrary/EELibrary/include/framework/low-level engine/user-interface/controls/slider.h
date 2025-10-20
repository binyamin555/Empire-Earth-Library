#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UISlider : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::Slider;

public: UISlider(unsigned long, class GERectangle const&, unsigned long, class UIForm*, unsigned long, unsigned long);
public: UISlider(class UISlider const&);
public: virtual ~UISlider();

protected: virtual void ButtonUp();
protected: virtual void ChangeRange(unsigned long);
public: virtual long CopyData();
public: virtual long DrawPolygons();
protected: virtual long MouseLButtonDown();
protected: virtual long MouseLButtonUp();
protected: virtual long MouseMove(class GE2DPoint const&);
public: virtual void SetLocation(class GE2DPoint const&);

public: long GetCurrentPoint(class GE2DPoint const&) const;
public: BOOL GetIsDragging() const;
public: void SetCurrentPoint(long, class GE2DPoint&) const;
public: void SetPageSize(unsigned long);
protected: void SetIsDragging(BOOL);
public: class UISlider& operator=(class UISlider const&);
public: long GetMaxRange() const;
public: long GetMinRange() const;
public: unsigned long GetRange() const;
public: unsigned long GetSliderStyle() const;
public: class GERectangle const& GetThumbRectangle() const;
protected: void DecrementByPageSize();
public: void GetLocFromRange(long, class GE2DPoint&) const;
public: unsigned long GetRangeFromLoc(class GE2DPoint const&) const;
protected: void IncrementByPageSize();
public: void SetCurrentRangeValue(long);
public: void SetRange(unsigned long, unsigned long);

};
