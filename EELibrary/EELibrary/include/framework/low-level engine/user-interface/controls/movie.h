#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UIMovie : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::Movie;

public: UIMovie(unsigned long, class GEMovie*, class GERectangle const&, class UIForm*, unsigned long);
public: UIMovie(class UIMovie const&);
public: virtual ~UIMovie();

public: virtual long CopyData();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();

public: class UIMovie& operator=(class UIMovie const&);
};
