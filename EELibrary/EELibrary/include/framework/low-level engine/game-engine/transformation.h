#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"


class GETransformation
{
public:
	IMPORT GETransformation();

	IMPORT float GetX() const;
	IMPORT float GetY() const;
	IMPORT float GetZ() const;

	IMPORT void SetX(float x);
	IMPORT void SetY(float y);
	IMPORT void SetZ(float z);

private:
	float m11;
	float m12;
	float m13;
	float m14;
	float m21;
	float m22;
	float m23;
	float m24;
	float m31;
	float m32;
	float m33;
	float m34;
	float m41;
	float m42;
	float m43;
	float m44;
};
