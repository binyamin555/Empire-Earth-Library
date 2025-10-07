#include "pch.h"

#include "ModTemplate.h"

#include <iostream>

#include "framework/low-level engine.h"
#include "modding.h"
#include "Logger.h"

#include "game-data/options.h"
#include "modding-api/events.h"


MOD_CLASS_NAME::MOD_CLASS_NAME()
    : MODDING_CORE_NAMESPACE::Mod(
        MOD_NAME, 
        MODDING_CORE_NAMESPACE::Version(
            MOD_VERSION_MAJOR, 
            MOD_VERSION_MINOR, 
            MOD_VERSION_PATCH
        )
    )
{
    
}

MOD_CLASS_NAME::~MOD_CLASS_NAME()
{
}

bool MOD_CLASS_NAME::OnStart()
{
    ee::events::OnProgramLoaded += []() {
        std::cout << "Program loaded" << std::endl;
	};

    return true;
}

DWORD MOD_CLASS_NAME::OnUpdate()
{
    /*
            Do stuff here, for most mods this will not be needed
            Because you will be using the event system to do stuff
            This loop must only be used if it can't be done in the event system
            Like for example if you want to detect a key press
    */

    /*
            At any time, you can call SetRunning(false)
            This will stop the thread at the end of the current loop
    */

    if (gISMouse != nullptr)
        if (gISMouse->currentDeltaPtr->left)
        {
            eelib::Logger::Info("Button clicked!");
            eelib::Logger::Info(ee::options::PlayerName->string);
        }

    return MOD_UPDATE_INTERVAL;
}

void MOD_CLASS_NAME::OnStop()
{
    
}
