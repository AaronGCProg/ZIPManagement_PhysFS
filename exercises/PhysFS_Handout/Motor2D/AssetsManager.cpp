#include "App.h"
#include "AssetsManager.h"


ModuleAssetsManager::ModuleAssetsManager() : Module()
{
	name = ("assetsManager");

	// TODO 0: Open the following link and check it: https://icculus.org/physfs/docs/html/physfs_8h.html
	// TODO 1: You must initialize and de-initialize the PhysFS API.


	// After initializing the API, you can uncomment this function. Only required when compiling in Debug.
	// PHYSFS_mount(".", nullptr, 1);
}


ModuleAssetsManager::~ModuleAssetsManager()
{
}

bool ModuleAssetsManager::Awake(pugi::xml_node& config)
{

	// TODO 2: Mount the desired ZIP with PhysFS.

	return true;
}


bool ModuleAssetsManager::CleanUp()
{
	return false;
}

SDL_RWops* ModuleAssetsManager::Load(const char* path) const
{
	char* buffer;
	uint bytes = Load(path, &buffer);

	// TODO 5: Check what is: https://wiki.libsdl.org/SDL_RWops
	// We will need a new method to load Music, FX and Textures from the memory.
	// Try to investigate SDL_RWops and Related Functions.

	return nullptr;

}


uint ModuleAssetsManager::Load(const char* path, char** buffer) const
{
	uint ret;
	
	// TODO 3: You want to return the number of bytes it has read from the file that we passed to this function. 
	// Maybe you want to search readBytes in the documentation, and investigate from there how to build the function.

	// Uncomment when you finished.
	// PHYSFS_close(file);

	return 1;
}


