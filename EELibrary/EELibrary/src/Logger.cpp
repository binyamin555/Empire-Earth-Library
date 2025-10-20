#include "pch.h"

#include "modding.h"
#include "Logger.h"
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>

namespace eelib {

class CurrentModNamePatternFlag : public spdlog::custom_flag_formatter {
public:
    void format(spdlog::details::log_msg const& msg, std::tm const& tm_time, spdlog::memory_buf_t& dest) override
    {
		using namespace ee::modding::core;

        if (IsModCurrentlyRunning()) {
            auto const& currentMod = GetCurrentlyRunningMod();
            std::string modName = "Mod:";
			modName += currentMod.GetModObject().GetName();
            dest.append(modName.data(), modName.data() + modName.size());
        }
        else {
			std::string noMod = "System";
			dest.append(noMod.c_str(), noMod.c_str() + noMod.length());
        }
	}

    std::unique_ptr<spdlog::custom_flag_formatter> clone() const override
    {
        return std::make_unique<CurrentModNamePatternFlag>();
	}
};

std::shared_ptr<spdlog::logger> Logger::_libLogger;

void Logger::Init(const char* name)
{
    if (_libLogger != nullptr)
        return;
    if (spdlog::get(name) != nullptr)
        return;

#ifdef _DEBUG
    if (GetConsoleWindow() == NULL)
        AllocConsole();

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitleA("EE Library Debug Console");

    // freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
    // freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
    // freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

    // Create thread to force console to be topmost
    // TODO: Hook lol
    CreateThread(
        NULL, NULL, [](LPVOID) -> DWORD {
            bool visible = true;

            while (true) {
                if (GetAsyncKeyState(VK_F5) & 1)
                    visible = !visible;

                if (visible) {
                    HWND consoleWindow = GetConsoleWindow();
                    if (consoleWindow != NULL) {
                        // Set the console as FUllscreen overlay and topmost and semi-transparent
                        //SetWindowLong(consoleWindow, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TRANSPARENT);
                        //SetLayeredWindowAttributes(consoleWindow, 0, static_cast<BYTE>(0.70 * 255), LWA_ALPHA);
                        //SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, NULL);
                        //SetWindowPos(consoleWindow, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
                    }
                } else {
                    ShowWindow(GetConsoleWindow(), SW_HIDE);
                }
                Sleep(500);
            }
            return 0;
        },
        NULL, NULL, NULL);
#endif

    _libLogger = spdlog::stdout_color_mt(name, spdlog::color_mode::automatic);
    spdlog::set_default_logger(_libLogger);
	auto formatter = std::make_unique<spdlog::pattern_formatter>();
	formatter->add_flag<CurrentModNamePatternFlag>('?').set_pattern("[%H:%M:%S] [From: %?] [%^%L%$] [thread %t] %v");
    _libLogger->set_formatter(std::move(formatter));
    _libLogger->set_level(spdlog::level::trace);
    //_libLogger->sinks().push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("Mods/Library.log", (1024 * 1024) * 5, 3, false));
}

void Logger::Uninit()
{
    _libLogger->flush();
#ifdef _DEBUG
    if (GetConsoleWindow() != NULL)
        FreeConsole();
#endif
}

}