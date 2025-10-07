#pragma once

#include <string>

#include "modding/.h"
#include "modding/version.h"

#include "EELibraryExports.h"


MODDING_CORE_NAMESPACE_BEGIN


class Mod {
public:
    EELIBRARY_API explicit Mod(const char* name);
    EELIBRARY_API explicit Mod(const char* name, Version const version);
    EELIBRARY_API virtual ~Mod();

    char const* GetName() const;
    Version const& GetVersion() const;

    EELIBRARY_API bool IsRunning() const;
    EELIBRARY_API bool IsInitialized() const;

    /*
            Called when the mod is starting up.
            This call block the game thread.
            This is the place to initialize your mod.
            Don't do any heavy work here!

            Return:
            1: Success, mod is initialized.
                    OnUpdate() will be called.
            0: Failure, mod is not initialized.
                    OnUpdate() will not be called.
    */
    EELIBRARY_API virtual bool OnStart() = 0;

    /*
            Called when the mod is running.
            This function is called from a separate thread.
            Do all your heavy work here :D
            Return:
			Time to wait before calling this function again (in milliseconds).
    */
    EELIBRARY_API virtual DWORD OnUpdate() = 0;

    /*
            Called when the mod is shutting down.
            This call block the game thread.
            This is the place to clean up your mod.
            The game (or maybe Windows) will try to
            kill the thread after a certain amount of time.
            So... Again don't do any heavy work here :)
    */
    EELIBRARY_API virtual void OnStop() = 0;

protected:
    friend class ModInstance;

    void Stop();
    void SetInitialized(bool initialized);

private:
    bool running = false;
    bool initialized = false;
    Version const version;

    std::string const name;
};


MODDING_CORE_NAMESPACE_END
