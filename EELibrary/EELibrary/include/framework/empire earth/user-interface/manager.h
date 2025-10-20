#pragma once

#include "framework/low-level engine.h"

#include "utils/memory.h"


namespace ee::ui {
	class EEUIManager : public UIManager {

	};


	inline MemoryPtr<EEUIManager, 0x009197A0> uiManager;
}