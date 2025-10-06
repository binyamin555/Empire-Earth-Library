#include "pch.h"

#include "ModTemplate.h"
#include <iostream>

#include "framework/low-level engine.h"
#include "Logger.h"

#include "game-data/options.h"
#include "modding-api/events.h"



MOD_NAME::MOD_NAME(void)
    : eelib::mod::Mod(MOD_NAME_STRING)
{
    SetVersion(MOD_VERSION_MAJOR, MOD_VERSION_MINOR, MOD_VERSION_PATCH);
}

MOD_NAME::~MOD_NAME(void)
{
}

bool MOD_NAME::OnStart()
{
    ee::events::OnProgramLoaded += []() {
        std::cout << "Program loaded" << std::endl;
	};

    return true;
}

bool MOD_NAME::OnUpdate()
{
    while (IsRunning()) {
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

        Sleep(MOD_UPDATE_INTERVAL);
    }
    /*std::cout << "ModTemplate::OnStart()" << std::endl;*/
    return true;
}

bool MOD_NAME::OnStop()
{
    /*std::cout << "ModTemplate::OnStop()" << std::endl;*/
    return true;
}
