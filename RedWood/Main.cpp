
#include "Headers/Main.h"

int main()
{
    InitWindow(HDHeight, HDWidth, "RedWood"); // Create program window

	Define(); // Define all values for all textures
	while(!WindowShouldClose())
	{
		BeginDrawing();

		Start(); //Start menu and main program 

		EndDrawing();
	}
	Remove();
}

