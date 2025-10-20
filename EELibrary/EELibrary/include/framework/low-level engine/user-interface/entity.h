#pragma once

#include "framework/low-level engine/.h"


class UIEntity {
	using EntityType = unsigned long;

protected:
	IMPORT UIEntity(EntityType entityType);
	IMPORT virtual ~UIEntity();

public:
	IMPORT EntityType GetType() const;

private:
	EntityType entityType;
};
