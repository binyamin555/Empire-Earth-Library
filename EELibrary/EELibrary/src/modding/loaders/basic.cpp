#include "pch.h"

#include "modding/loaders/basic.h"

#include "EELibrary.h"
#include "Logger.h"


using namespace MODDING_LOADER_NAMESPACE;
using namespace eelib;


void BasicLoader::Load(Path modFolder)
{
    std::vector<std::filesystem::path> modPaths;
    for (const auto& entry : std::filesystem::directory_iterator(modFolder))
        if (entry.is_regular_file() && entry.path().extension() == ".dll")
            modPaths.push_back(entry.path());

    auto& modManager = *instance->GetModManager();

    for (const auto& path : modPaths) {
		ee::modding::core::ModInstance* mod;
        try {
            Logger::Info("Loading mod {}...", path.filename().string());
            mod = &modManager.LoadMod(path);
            auto const& modObject = mod->GetModObject();
            Logger::Info("Loaded mod {} v{}", modObject.GetName(), modObject.GetVersion().GetString());
        }
        catch (std::exception& e) {
            Logger::Error("Failed to load mod {}: {}", path.filename().string(), e.what());
            MessageBoxA(NULL, e.what(), "EE Library", MB_OK);
            continue;
        }

        Logger::Info("Starting mod {}...", mod->GetModObject().GetName());
        modManager.StartMod(*mod);
        Logger::Info("Started mod {}", mod->GetModObject().GetName());
    }
}
