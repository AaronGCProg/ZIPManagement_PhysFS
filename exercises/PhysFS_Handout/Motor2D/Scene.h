#ifndef __MODULESCENE_H__
#define __MODULESCENE_H__

#include "Module.h"

class ModuleScene : public Module
{
public:

	ModuleScene();

	// Destructor
	virtual ~ModuleScene();

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

private:

	// We load all the ZIP texture files
	void LoadTexFile(const pugi::xml_document& dataFile);

	// We load all the ZIP fx files
	void LoadFxFile(const pugi::xml_document& dataFile);

	// We load and play the desired music from the ZIP
	void LoadMusFile(const pugi::xml_document& dataFile);

private:

	SDL_Texture* texture;

};

#endif // __MODULESCENE_H__
