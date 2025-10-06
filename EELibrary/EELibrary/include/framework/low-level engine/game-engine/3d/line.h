#pragma once

#include "framework/low-level engine/.h"

#include "./point.h"
#include "./vector.h"


class GE3DLine
{
public:
	IMPORT GE3DLine();

	GE3DPoint start;
	GEVector direction;
};
