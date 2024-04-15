
#include "Headers/Main.h"

int main()
{
    InitWindow(HDHeight, HDWidth, "RedWood"); // Create program window

	Define(); // Define all values for all textures
	while(!WindowShouldClose())
	{
		BeginDrawing();

		

		EndDrawing();
	}
	Remove();
}

