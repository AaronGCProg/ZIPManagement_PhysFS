#include "p2Defs.h"
#include "p2Log.h"
#include "App.h"
#include "Audio.h"
#include "AssetsManager.h"

#include "Brofiler/Brofiler/Brofiler.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )


ModuleAudio::ModuleAudio() : Module(), music(NULL)
{
	name.create("audio");
}


// Destructor
ModuleAudio::~ModuleAudio()
{}


// Called before render is available
bool ModuleAudio::Awake(pugi::xml_node& config)
{
	BROFILER_CATEGORY("Audio Awake", Profiler::Color::AliceBlue);

	bool ret = true;
	SDL_Init(0);

	fxFolder.create(config.child("folder").child_value());


	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		active = false;
		ret = true;
	}


	// load support for the JPG and PNG image formats
	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);


	if ((init & flags) != flags)
	{
		active = false;
		ret = true;
	}


	//Initialize SDL_mixer
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		active = false;
		ret = true;
	}


	return ret;
}


// Called before quitting
bool ModuleAudio::CleanUp()
{
	if (!active)
		return true;


	if (music != NULL)
		Mix_FreeMusic(music);

	fx.clear();

	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);

	return true;
}


// Play a music file
bool ModuleAudio::PlayMusic(const char* path, float fade_time)
{
	bool ret = true;

	if (!active)
		return false;


	if (music != NULL)
	{


		if (fade_time > 0.0f)
			Mix_FadeOutMusic(int(fade_time * 1000.0f));
		else
			Mix_HaltMusic();


		// this call blocks until fade out is done
		Mix_FreeMusic(music);
	}


	// TODO 6: This TODO is a gift for you. If you finished TODO 5 correctly, you only need to uncomment this, but check how is working now.
	// music = Mix_LoadMUS_RW(app->assetManager->Load(path), 1);


	if (music == NULL)
		ret = false;
	else
	{
		if (fade_time > 0.0f)
		{
			if (Mix_FadeInMusic(music, -1, (int)(fade_time * 1000.0f)) < 0)
				ret = false;
		}
		else
		{
			if (Mix_PlayMusic(music, -1) < 0)
				ret = false;
		}
	}


	return ret;
}


// Load WAV
unsigned int ModuleAudio::LoadFx(const char* path)
{
	unsigned int ret = 0;

	if (!active)
		return 0;

	Mix_Chunk* chunk = nullptr;

	// TODO 6: This TODO is a gift for you. If you finished TODO 5 correctly, you only need to uncomment this, but check how is working now.
	// chunk = Mix_LoadWAV_RW(app->assetManager->Load(path), 1);

	if (chunk == NULL)
	{

	}
	else
	{
		fx.push_back(chunk);
		ret = fx.size();
	}

	return ret;
}


// Play WAV
bool ModuleAudio::PlayFx(unsigned int id, int repeat)
{
	bool ret = false;
	id += 0;
	if (!active)
		return false;


	if (id > 0 && id <= fx.size())
		Mix_PlayChannel(-1, fx[id - 1], repeat);


	return ret;
}

