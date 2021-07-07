#include <stdio.h>
#include <Window.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char* args[])
{
	Window view = Window(SCREEN_WIDTH, SCREEN_HEIGHT);

	//Start up SDL and create window
	if (!view.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!view.loadResources())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			view.update();
		}
	}

	return 0;
}

