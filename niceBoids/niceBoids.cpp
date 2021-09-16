#include <stdio.h>

#include <Engine.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char* args[])
{
	Engine engine = Engine(SCREEN_WIDTH, SCREEN_HEIGHT);

	//Start up SDL and create window
	if (!engine.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		engine.simulate();
	}

	return 0;
}

