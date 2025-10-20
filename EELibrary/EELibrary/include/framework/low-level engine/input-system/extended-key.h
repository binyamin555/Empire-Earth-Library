#pragma once

#include "framework/low-level engine/.h"

#include "./entity.h"


class ISExtendedKey : public ISEntity {
public: IMPORT virtual unsigned long GetIndex() const;
};
