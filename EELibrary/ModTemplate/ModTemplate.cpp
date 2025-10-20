#include "pch.h"

#include "ModTemplate.h"

#include <iostream>

#include "framework/low-level engine.h"
#include "framework/empire-earth.h"
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

    static unsigned long maxVideoMemory = 0;
	auto rasterizer = GERasterizer::GetActiveRasterizer();
    if (rasterizer != nullptr)
    {
        if (maxVideoMemory == 0) {
            if (!rasterizer->GetTotalVideoMemory(0, maxVideoMemory)) {
                eelib::Logger::Info("Max video memory: {}", maxVideoMemory);
            }
            else {
                eelib::Logger::Info("Failed to get max video memory");
            }
        }

        auto& uiManager = *&ee::ui::uiManager;
        if (&uiManager != nullptr) {
			auto& currentForm = *uiManager.GetCurrentForm();
            if (&currentForm != nullptr && currentForm.GetFormID() == 12) {
				auto labelControl = currentForm.GetControl(5);
                UITextLabel* label;
                if (labelControl != nullptr && labelControl->Is<UITextLabel>(label)) {
					unsigned long availableVideoMemory;
                    if (!rasterizer->GetAvailableVideoMemory(0, availableVideoMemory)) {
					    auto currentVideoMemory = maxVideoMemory - availableVideoMemory;
						std::string s = std::to_string(currentVideoMemory / (1024 * 1024)) + " / " + std::to_string(maxVideoMemory / (1024 * 1024)) + " MB (" + std::to_string(100 * currentVideoMemory / maxVideoMemory) + "%)";
                        label->SetText(UWideString(s.data()));
                    }
                    else {
						label->SetText(UWideString("Error retrieving video memory"));
                    }
                }
            }
		}
    }

    if (gISMouse != nullptr) {
        auto const& mouse = *gISMouse;
        if (mouse.entities.axes->left->JustPressed())
        {
            eelib::Logger::Info("Button clicked!");
            
            auto& uiManager = *&ee::ui::uiManager;

			auto formCount = uiManager.GetFormCount();
            auto& currentForm = *uiManager.GetCurrentForm();

            auto const formId = currentForm.GetFormID();
			eelib::Logger::Info("Current form ID: {}", formId);

			auto const controlCount = currentForm.GetControlCount();

			eelib::Logger::Info("Current form has {} controls", controlCount);			

            for (unsigned long i = 0; i < controlCount; ++i) {
                auto const control = currentForm.GetControl(i);
                if (control != nullptr) {
					auto const controlType = control->GetType();

                    UIButton* button;
					UITextLabel* textLabel;

                    if (control->Is<UIButton>(button)) {
						UWideString buttonHelpText;
                        if (button->GetHelpString(buttonHelpText)) {
                            eelib::Logger::Info("Control {} is a UIButton: {}", i, buttonHelpText.string);
                        }
                        else {
                            eelib::Logger::Info("Control {} is a UIButton with no help text", i);
                        }
                    }
                    else if (control->Is<UITextLabel>(textLabel)) {
                        eelib::Logger::Info("Control {} is a UITextLabel: {}", i, textLabel->GetText(0).string);
                    }
                    else {
                        eelib::Logger::Info("Control {} is of unknown type: {}", i, static_cast<unsigned long>(controlType));
					}
                }
			}

            currentForm.RedrawIntersectControls(currentForm.GetRectangle());
        }
    }

    return MOD_UPDATE_INTERVAL;
}

void MOD_CLASS_NAME::OnStop()
{
    
}
