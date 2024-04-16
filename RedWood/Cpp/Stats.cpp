#include "../Headers/Stats.h"
#include "../Headers/Photos.h"
#include "raylib.h"

bool ShowStats = false;
bool RepeatFunction = false;
int Data[3];
void Stats()
{
	bool HovOnReturn = CheckCollisionPointRec(GetMousePosition(), { 10,10,(float)ReturnButton.width,(float)ReturnButton.height });
	if (ShowStats)
	{
	
		DrawTexture(TestBackground, 0, 0, RAYWHITE);
		DrawText("Statistics:", 270, 30, 150, BLACK);
		
		DrawRectangle(350, 330, 78, 28, WHITE);
		DrawTexture(MaxPic, 320, 260, RAYWHITE);

		DrawRectangle(354, 488, 78, 39, WHITE);
		DrawTexture(MinPic, 325, 420, RAYWHITE);

		DrawTexture(AveragePic, 332.2, 575, RAYWHITE);

		
		AverageMaxMinCalculate(AllResults, Data); // Get min,max, average score in the Data array
	
		RepeatFunction = true;
		string MaxString = to_string(Data[0]), MinString = to_string(Data[1]), AverageString = to_string(Data[2]);

		//Show all Stats
		DrawText((const char*)MaxString.data(), 510, 300, 60,BLACK);
		DrawText((const char*)MinString.data(), 510, 460, 60, BLACK);
		if (SizeAllResults == 0)
		{
			DrawText("0", 510, 610, 60, BLACK);
		}
		else
		{
			DrawText((const char*)AverageString.data(), 510, 610, 60, BLACK);
		}
		
		
		//Return button to return back
		DrawTexture(ReturnButton, 10, 10, RAYWHITE);
		if (HovOnReturn)
		{
			DrawTexture(ReturnButton, 10, 10, GREEN);
		}
		if (HovOnReturn && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			ShowStats = false;
			RepeatFunction = false; // Set the repeat variable to be ready for the next opening of Stats
			
			Data[0] = Data[1] = Data[2] = 0; //Reset all values
		}
	}
}
void AverageMaxMinCalculate(double Arr[], int Data[3])
{
	// Data[3]
	// 0 - Max
	// 1 - Min
	// 2 - Average
	
	if (RepeatFunction == false)
	{
		int Max = Arr[0], Min = Arr[0];
		double Sum = 0;
		for (int i = 0; i < SizeAllResults; i++)
		{
			if (Arr[i] > Max)
			{
				Max = Arr[i];
			}
			if (Arr[i] < Min)
			{
				Min = Arr[i];
			}
			Sum += Arr[i];
		}
		Data[0] = Max;
		Data[1] = Min;
		Data[2] = Sum / SizeAllResults;
	}

	RepeatFunction = true; // Stop the repeating of the function bymaking it true
}