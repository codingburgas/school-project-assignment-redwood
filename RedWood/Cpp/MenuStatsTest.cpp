#include "../Headers/MenuStatsTest.h"
#include "../Headers/Quiz.h"
#include "../Headers/Start.h"
#include "../Headers/Photos.h"
#include "../Headers/Stats.h"
#include "../Headers/Test.h"
#include "../Headers/Team.h"
#include "raylib.h"

void Menu()
{
	
		bool HoverOnStats = CheckCollisionPointRec(GetMousePosition(), { 300,200,(float)StatsPic.width,(float)StatsPic.height });
		bool HoverOnTest = CheckCollisionPointRec(GetMousePosition(), { 810,200,(float)TestPic.width,(float)TestPic.height });
		bool HovOnReturn = CheckCollisionPointRec(GetMousePosition(), { 10,10,(float)ReturnButton.width,(float)ReturnButton.height });
		if (ChangeToTest)
		{
			
			//Draw options and background
			DrawTexture(MenuBackground, 0, 0, RAYWHITE);
			DrawTexture(StatsPic, 200, 250, RAYWHITE);
			DrawTexture(TestPic, 700, 250, RAYWHITE);
			DrawTexture(ReturnButton, 10, 10, RAYWHITE);

			DrawText("Stats:", 300, 200, 50, BLACK);
			DrawText("Test:", 810, 200, 50, BLACK);

			// ShowStats and ShowTest are used to switch between the test, stats and menu
			if (HoverOnStats && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
			{		
				ShowStats = true;
			}
			if (HoverOnTest && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
			{
				ShowTest = true;
			}
			
			if (HovOnReturn)
			{
				DrawTexture(ReturnButton, 10, 10, GREEN);
			}
			if (HovOnReturn && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				ChangeToTest = false;
			}
		}
		Stats();
		Test();
	
}