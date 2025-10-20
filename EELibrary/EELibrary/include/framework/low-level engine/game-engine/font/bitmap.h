#pragma once

#include "framework/low-level engine/.h"

#include "framework/low-level engine/utils/reference-counter.h"


class GEFontBitmap : public UReferenceCounter {
public: IMPORT GEFontBitmap(class GEFontBitmap const&);
public: IMPORT class GEFontBitmap& operator=(class GEFontBitmap const&);
public: IMPORT BOOL operator==(class GEFont*);
public: IMPORT GEFontBitmap(class GERasterizer*, class GEFont*, unsigned long);
protected: IMPORT virtual ~GEFontBitmap();
private: IMPORT class GETexture* CreateNewFontTexture(class GEScreen*);
private: IMPORT long CreateSurfaceAlpha(class GESurface*);
public: IMPORT long Draw(class GEText*, class GERasterizer*, unsigned long);
public: IMPORT long Draw(class GEText*, class GERectangle const&, class GERasterizer*, unsigned long);

private:
	uint32_t unk0[7];
};
