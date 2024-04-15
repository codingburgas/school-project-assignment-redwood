#include "../Headers/Photos.h"
#include "raylib.h"

// Declare the photos' textures 
Texture2D StartMenuBackground;
Texture2D TeamBackground;

Texture2D StartButton;
Texture2D TeamViewButton;
Texture2D ExitButton;
Texture2D ReturnButton;

Texture2D Logo;

Texture2D Georgiev;
Texture2D Stoqnov;
Texture2D Rusev;
Texture2D Rusinov;
Texture2D Semerdjiev;
Texture2D Qnakiev;

Texture2D MenuBackground;
Texture2D StatsPic;
Texture2D TestPic;

Texture2D TestBackground;
Texture2D OptionA;
Texture2D OptionB;
Texture2D OptionC;
Texture2D OptionD;

Texture2D MinPic;
Texture2D MaxPic;
Texture2D AveragePic;
//Give definitions of all photos inside main
void Define()
{
   StartMenuBackground = LoadTexture("Photos/Background.png");
   StartButton = LoadTexture("Photos/Begin.png");
   TeamViewButton = LoadTexture("Photos/Team.png");
   ExitButton = LoadTexture("Photos/Exit.png");
   Logo = LoadTexture("Photos/Logo.png");
   TeamBackground = LoadTexture("Photos/TeamBackground.png");
   ReturnButton = LoadTexture("Photos/ReturnButton.png");
   Georgiev = LoadTexture("Photos/Georgiev.png");
   Stoqnov = LoadTexture("Photos/Stoqnov.png");
   Rusev = LoadTexture("Photos/Rusev.png");
   Rusinov = LoadTexture("Photos/Rusinov.png");
   Semerdjiev = LoadTexture("Photos/Semerdjiev.png");
   Qnakiev = LoadTexture("Photos/Qnakiev.png");
   MenuBackground = LoadTexture("Photos/MenuBackground.png");
   StatsPic = LoadTexture("Photos/Stats.png");
   TestPic = LoadTexture("Photos/Test.png");
   TestBackground = LoadTexture("Photos/TestBackground.png");
   OptionA = LoadTexture("Photos/OptionA.png");
   OptionB = LoadTexture("Photos/OptionB.png");
   OptionC = LoadTexture("Photos/OptionC.png");
   OptionD = LoadTexture("Photos/OptionD.png");
   MinPic = LoadTexture("Photos/MinPic.png");
   MaxPic = LoadTexture("Photos/MaxPic.png");
   AveragePic = LoadTexture("Photos/AveragePic.png");
}

//Undefine all textures above
void Remove()
{
	UnloadTexture(StartMenuBackground);
	UnloadTexture(StartButton);
	UnloadTexture(TeamViewButton);
	UnloadTexture(ExitButton);
	UnloadTexture(Logo);
	UnloadTexture(TeamBackground);
	UnloadTexture(ReturnButton);
	UnloadTexture(Georgiev);
	UnloadTexture(Stoqnov);
	UnloadTexture(Rusev);
	UnloadTexture(Rusinov);
	UnloadTexture(Semerdjiev);
	UnloadTexture(Qnakiev);
	UnloadTexture(MenuBackground);
	UnloadTexture(TestPic);
	UnloadTexture(StatsPic);
	UnloadTexture(TestBackground);
	UnloadTexture(OptionA);
	UnloadTexture(OptionB);
	UnloadTexture(OptionC);
	UnloadTexture(OptionD);
	UnloadTexture(MaxPic);
	UnloadTexture(MinPic);
	UnloadTexture(AveragePic);
}

