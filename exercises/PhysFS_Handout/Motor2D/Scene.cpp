#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "AssetsManager.h"

ModuleScene::ModuleScene() : Module(), texture(nullptr)
{
	name.create("scene");
}

ModuleScene::~ModuleScene()
{}

// Called before the first frame
bool ModuleScene::Start()
{
	
	// TODO 4: Uncomment all of this and resolve how to load the document from the memory with the link below.

	// char* buffer;
	// pugi::xml_document dataFile;

	// ! Here we are using the function you just prepared, if it's not working return to TODO 3.
	// int bytesFile = app->assetManager->Load("data.xml", &buffer);

	// Loading document from memory with PUGI: https://pugixml.org/docs/manual.html#loading.memory
	// pugi::xml_parse_result result = ¿?;

	// RELEASE_ARRAY(buffer);

	// LoadTexFile(dataFile);
	// LoadFxFile(dataFile);
	// LoadMusFile(dataFile);

	return true;
}


// Called each loop iteration
bool ModuleScene::Update(float dt)
{
	if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
		app->audio->PlayFx(1);

	return true;
}

// Called each loop iteration
bool ModuleScene::PostUpdate()
{
	app->render->Blit(texture, 0, 0);

	return true;
}

// Called before quitting
bool ModuleScene::CleanUp()
{
	return true;
}

void ModuleScene::LoadTexFile(const pugi::xml_document& dataFile)
{
	pugi::xml_node tex_node = dataFile.child("data").child("texture");
	texture = app->tex->Load(tex_node.attribute("file").as_string());
}

void ModuleScene::LoadFxFile(const pugi::xml_document& dataFile)
{
	pugi::xml_node fx_node = dataFile.child("data").child("fx");
	app->audio->LoadFx(fx_node.attribute("file").as_string());
}

void ModuleScene::LoadMusFile(const pugi::xml_document& dataFile)
{
	pugi::xml_node mus_node = dataFile.child("data").child("mus");
	app->audio->PlayMusic(mus_node.attribute("file").as_string());
}