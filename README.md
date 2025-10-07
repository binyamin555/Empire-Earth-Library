# Empire-Earth-Library

This project is an attempt at making a modding API for Empire Earth.

There are currently 2 projects in the VS solution:
1) EELibrary - provides the mod manager, loader and game API.
2) ModTemplate - a template for a single mod.


## Mod Template

To use the mod template, you should first clone the repository and open it in Visual Studio.

To configure the mod, open the `mod-config.h` file and edit the following:
* `EE_MOD` - the mod name. this must be a valid C++ identifier. (e.g. `MyAwesomeMod`)
* `MOD_NAME` - mod title. used for display purposes. change this to something nicer. (e.g. `"My Awesome Mod"` - note the quotes)
* `MOD_VERSION_MAJOR` - major version
* `MOD_VERSION_MINOR` - minor version
* `MOD_VERSION_PATCH` - patch

> Note: Building the `ModTemplate` project will produce a `.dll` at `P:\Empire Earth\Empire Earth\Mods\`.
> If this is not the directory in which the game exists (it's most likely isn't), you should change this value.
> The `Mods\` directory should be in the same directory as the game `.exe` file.


## Development

Building the `EELibrary` project can be done via Visual Studio.

> Note: Building this project will try to copy the output `EELibrary.dll` file to `P:\Empire Earth\Empire Earth`.
> This path is most likely not where the game sits on your system. You should change this path to the path in which
> the main `.exe` file of the game sits.
>
> To change this, in Visual Studio's `Solution Explorer`, right-click on the `EELibrary` project -> `Properties` -> `Build Events / Post-Build Event`. Change the path at the end of the `Command Line` value to the path of your EE install directory.
