#pragma once

#include "framework/low-level engine/.h"

#include "./control.h"


IMPORT class UIBitmap : public UIControl {
public:
	static constexpr UIControl::Type StaticType = UIControl::Type::Bitmap;

public: UIBitmap(unsigned long, class GEBitmap*, class GERectangle const&, class UIForm*, unsigned long);
public: UIBitmap(class UIBitmap const&);
public: virtual ~UIBitmap();
public: class UIBitmap& operator=(class UIBitmap const&);
public: void SetBitmap(class GEBitmap*);

public: virtual long CopyData();
public: virtual long DrawPolygons();
public: virtual long DrawTextA();
};
