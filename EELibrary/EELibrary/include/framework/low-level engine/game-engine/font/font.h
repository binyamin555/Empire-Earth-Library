#pragma once

#include "framework/low-level engine/.h"

#include "framework/low-level engine/utils/reference-counter.h"
#include "framework/low-level engine/string/string.h"

#include "./bitmap.h"


class GEFont : public UReferenceCounter {
public:
	using Size = uint32_t;
	using Height = uint32_t;

	enum class Flags : uint32_t {
		None = 0,
		Bold = 1 << 0,
		Italic = 1 << 1,
		Underline = 1 << 2,
	};

	enum class Quality : uint32_t {
		Default = 0,
		Low = 1,
		Antialiased = 2,
	};

public: BOOL CompareFont(class UString const&, unsigned long, unsigned long, unsigned long);
public: BOOL GetHasFontBitmap() const;
public: void SetFontBitmap(class GEFontBitmap*);
public: GEFont(class GEFont const&);
public: class GEFont& operator=(class GEFont const&);
public: GEFont(class UString const&, unsigned long, unsigned long, unsigned long);
public: virtual ~GEFont();

private:
	UString name;
	HFONT handle;
	Quality quality;
	Flags flags;
	GEFontBitmap* bitmap;
	Size size;
	Height height;
};
