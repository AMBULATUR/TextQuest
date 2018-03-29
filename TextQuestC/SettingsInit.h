#pragma once
#include <fstream>
#include <sstream>
using namespace std;
class SettingsInit
{
	//typedef struct __attribute__((__packed__))  - STOP, œ¿ Œ¬¿ÕÕ¿ﬂ Ã¿ÿ»ÕÕŒ-Õ≈«¿¬»—»Ã¿ﬂ —“–” “”–¿ ¬ ﬂ«€ ≈ —»(HE Cpp)
	struct SetUp{
		int Xresolution;
		int Yresolution;
		bool FullScreenMode;

		int Music;
		int Effects;
		bool MMusic;
		bool MEffects;
	} Foo;


	FILE * ptrFile;
public:

	void InitCheck()
	{
		SetUp params;
		ptrFile = fopen("settings.ini", "r");
		if (ptrFile != NULL)
			LoadSettings(params);
		else if (ptrFile == NULL)
			FirstInit();


	}
	void FirstInit()
	{
		sf::RenderWindow window(VideoMode(0, 0), "TextQuest", Style::Fullscreen);
		Vector2u WindowVector = window.getSize();

		ptrFile = fopen("settings.ini", "w");

		/// <summary>
		/// [Optimal]Resolution
		/// </summary>
		//[VIDEO]
		int XResolution = WindowVector.x;
		int YResolution = WindowVector.y;
		bool FullScreenMode = false;
		//[AUDIO]
		int Music = 50;
		int Effects = 50;
		bool MMusic = false;
		bool MEffects = false;
		//[Gameplay]
		//[Control]
		
		///END

		stringstream ParsW, ParsA, ParsG, ParsC;
		string str;
		const char *s1;
		ParsW << "[Video]\nXResolution = " << XResolution << "\nYResolution = " << YResolution << "\nFullScreenMode = " << FullScreenMode;
		str = ParsW.str();
		s1 = str.c_str();
		fputs(s1, ptrFile);
		ParsA << "\n[Audio]\nMusic = " << Music << "\nEffects = " << Effects << "\nMMusic = " << MMusic << "\nMEffects = " << MEffects;
		str = ParsA.str();
		s1 = str.c_str();
		fputs(s1, ptrFile);
		ParsG << "\n[GamePlay]";
		str = ParsG.str();
		s1 = str.c_str();
		fputs(s1, ptrFile);
		ParsC << "\n[Control]";
		s1 = str.c_str();
		str = ParsC.str();
		fputs(s1, ptrFile);


		fclose(ptrFile);
	}
	void ChangeInit(int i)
	{
	}
	void ChangeInit(bool i)
	{
	}
	void UpdateSettings()
	{

	}
	void LoadSettings(SetUp params)
	{
		struct SetUp *ptrizen = &params;
		ptrizen->Xresolution;
		ptrizen.Yresolution;
		ptrparams.FullScreenMode;
		ptrparams.Music;
		ptrparams.Effects;
		ptrparams.MMusic;
		ptrparams.MEffects;

		ptrFile = fopen("settings.ini", "r");
		fclose(ptrFile);
	}
};