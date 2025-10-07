#pragma once

#include "modding.h"

#include "mod-config.h"

class MOD_CLASS_NAME : public ee::modding::core::Mod {
public:
    MOD_CLASS_NAME(void);
    ~MOD_CLASS_NAME(void);

    bool OnStart() override;
    DWORD OnUpdate() override;
    void OnStop() override;
};
