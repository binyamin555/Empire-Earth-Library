#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"

#include "./vector.h"
#include "../2d/point.h"


class GE3DPoint
{
public:
	IMPORT void Clear();

	IMPORT GE3DPoint& operator-=(GEVector const& vector);
	IMPORT BOOL operator==(GE3DPoint const& other) const;
	IMPORT void ComputeVectorTo(GE3DPoint const& other, GEVector& outVector) const;
	IMPORT float DistanceTo(GE3DPoint const& other) const;
	IMPORT float DistanceToSquared(GE3DPoint const& other) const;
	IMPORT GE2DPoint Get2DPoint() const;
	IMPORT void SetXYZ(float x, float y, float z);

	float x;
	float y;
	float z;
};
