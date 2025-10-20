#pragma once

#include "framework/low-level engine/.h"


IMPORT class GEColor {
public: GEColor();
public: void Normalize();
public: long Load(class FSFile&);
public: long Save(class FSFile&);

public: 
	GEColor(float red, float green, float blue)
		: r(red), g(green), b(blue) { }

public:
	float r;
	float g;
	float b;
};
