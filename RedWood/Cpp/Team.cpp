#include "../Headers/Team.h"
#include "raylib.h"
#include "../Headers/Photos.h"

bool ChangeToTeam = 0;

void Team()
{
	bool HovOnReturn = CheckCollisionPointRec(GetMousePosition(), { 10,10,(float)ReturnButton.width,(float)ReturnButton.height });
	if (ChangeToTeam)
	{
		//Team information
		DrawTexture(TeamBackground, 0, 0, RAYWHITE);
		DrawText("Developers:", 195, 30,150, BLACK);

		DrawTexture(Georgiev, 30, 240, RAYWHITE);
		DrawTexture(Stoqnov, 230, 240, RAYWHITE);
		DrawTexture(Rusev, 460, 240, RAYWHITE);
		DrawTexture(Rusinov, 650, 240, RAYWHITE);
		DrawTexture(Semerdjiev, 830, 240, RAYWHITE);
		DrawTexture(Qnakiev, 1050, 240, RAYWHITE);

		DrawText("Georgi Georgiev", 40, 450, 23, BLACK);
		DrawText("Georgi Stoqnov", 250, 450, 23, BLACK);
		DrawText("Kristiqn Rusev", 477, 450, 23, BLACK);
		DrawText("Boris Rusinov", 666, 450, 23, BLACK);
		DrawText("Aleks Semerdjiev", 835, 450, 23, BLACK);
		DrawText("Nikolai Qnakiev", 1068, 450, 23, BLACK);
		//Return button hover and if clicked
		DrawTexture(ReturnButton, 10, 10, RAYWHITE);
		if (HovOnReturn)
		{
			DrawTexture(ReturnButton, 10, 10, GREEN);
		}
		if (HovOnReturn && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			ChangeToTeam = false;
		}
	}
}