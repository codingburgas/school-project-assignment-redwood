#include "../Headers/Start.h"
#include "../Headers/Photos.h"
#include "../Headers/Team.h"
#include "../Headers/Stats.h"
#include "../Headers/MenuStatsTest.h"
#include "raylib.h"
#include <cstdlib> 

bool ChangeToTest = false;
bool AllowToShowStartMenu = ChangeToTest == false && ChangeToTeam == false; //If all other menus are hidden, the start menu is shown

void Start()
{

	bool HovOnStart = CheckCollisionPointRec(GetMousePosition(), { 390, 150, (float)StartButton.width, (float)StartButton.height });
	bool HovOnTeamView = CheckCollisionPointRec(GetMousePosition(), { 410, 310, (float)TeamViewButton.width, (float)TeamViewButton.height });
	bool HovOnExit = CheckCollisionPointRec(GetMousePosition(), { 410, 470, (float)ExitButton.width, (float)ExitButton.height });

	if (AllowToShowStartMenu)
	{
		//Draw Start menu buttons and logo
		DrawTexture(StartMenuBackground, 0, 0, RAYWHITE);
		DrawTexture(StartButton, 390, 150, RAYWHITE);
		DrawTexture(TeamViewButton, 410, 310, RAYWHITE);
		DrawTexture(ExitButton, 410, 470, RAYWHITE);
		DrawTexture(Logo, 20, 20, RAYWHITE);

		

		//Buttons when they're hovered.
		if (HovOnStart)
		{
			DrawTexture(StartButton, 390, 150, GREEN);
		}
		if (HovOnTeamView)
		{
			DrawTexture(TeamViewButton, 410, 310, GREEN);
		}
		if (HovOnExit)
		{
			DrawTexture(ExitButton, 410, 470, GREEN);
		}

		if (HovOnExit && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ChangeToTeam == false && ShowStats == false && ChangeToTest == false)
		{
			//Delete all textures and stop the program if the exit button is pressed
			Remove();

			exit(NULL);
		}
		if (HovOnTeamView && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ShowStats == false && ChangeToTest == false)
		{
			ChangeToTeam = true;
		}
		if (HovOnStart && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ChangeToTeam == false && ShowStats == false && ChangeToTest == false)
		{			
			ChangeToTest = true;
		}
    }



	Team(); // Team show when Team button is clicked
	Menu(); // Test start if start button is pressed
}