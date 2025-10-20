#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UIGraph : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::Graph;

public: UIGraph(unsigned long, class GERectangle const&, class UIForm*, unsigned long, unsigned long);
public: UIGraph(class UIGraph const&);
public: virtual ~UIGraph();

public: class UIGraph& operator=(class UIGraph const&);

public: virtual long CopyData();
public: virtual long DrawXAxisText();
public: virtual long DrawYAxisText();
public: virtual long DrawGridText();
public: virtual long DrawTitleText();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
public: virtual void SetFont(class GEFont*);
public: virtual void SetGraph(class UGraph const&);
public: virtual long UpdateKeyboard();
public: virtual long UpdateMouse(class GE2DPoint const&);
public: virtual void TabbedTo();
public: virtual void TabbedFrom();
public: virtual void ZoomIn(class GE2DPoint const&);
public: virtual void ZoomOut();

public: class GERectangle const& GetGraphRectangle();
public: float GetLineOpacity();
public: class GE2DPoint const& GetZoomLocation();

public: void SetDrawGrid(BOOL);
public: void SetLabelGrid(BOOL);
public: void SetLabelXAxis(BOOL);
public: void SetLabelYAxis(BOOL);
public: void SetLabelGraph(BOOL);
public: void SetLineOpacity(float);
public: void SetNumberOfGridDivisionsX(unsigned long);
public: void SetNumberOfGridDivisionsY(unsigned long);
public: void SetZoomScale(float);
public: void SetZoomIncrement(float);
public: void SetFontColor(class GEColor const&);

};
