#pragma once
#include <fstream>
#include <sstream>
using namespace std;
class SettingsInit
{
public:
	//typedef struct __attribute__((__packed__))  - STOP, œ¿ Œ¬¿ÕÕ¿ﬂ Ã¿ÿ»ÕÕŒ-Õ≈«¿¬»—»Ã¿ﬂ —“–” “”–¿ ¬ ﬂ«€ ≈ —»(HE Cpp)
	struct SetUp {
		int Xresolution;
		int Yresolution;
		bool FullScreenMode;

		int Music;
		int Effects;
		bool MMusic;
		bool MEffects;
	};


	FILE * ptrFile;
//public:

	SetUp * InitCheck()
	{
		SetUp params;
		ptrFile = fopen("settings.ini", "r");
		if (ptrFile != NULL)
			return LoadSettings(params);
		else if (ptrFile == NULL)
			return FirstInit(params);
		else
		{
			return 0;
		}


	}
	SetUp* FirstInit(SetUp &params)
	{
		sf::RenderWindow window(VideoMode(0, 0), "TextQuest", Style::Fullscreen);
		Vector2u WindowVector = window.getSize();

		ptrFile = fopen("settings.ini", "w");
		struct SetUp *ptrizen = &params;

		/// <summary>
		/// [Optimal]Resolution
		/// </summary>



		//[VIDEO]
		ptrizen->Xresolution = WindowVector.x;
		ptrizen->Yresolution = WindowVector.y;
		ptrizen->FullScreenMode = false;
		//[AUDIO]
		ptrizen->Music = 30;
		ptrizen->Effects = 11;
		ptrizen->MMusic = true;
		ptrizen->MEffects = false;
		//[Gameplay]
		//[Control]

		///END


		stringstream ParsW, ParsA, ParsG, ParsC;
		string str;
		const char *s1;
		ParsW << "[Video]\nXResolution = " << ptrizen->Xresolution << "\nYResolution = " << ptrizen->Yresolution << "\nFullScreenMode = " << ptrizen->FullScreenMode;
		str = ParsW.str();
		s1 = str.c_str();
		fputs(s1, ptrFile);
		ParsA << "\n[Audio]\nMusic = " << ptrizen->Music << "\nEffects = " << ptrizen->Effects << "\nMMusic = " << ptrizen->MMusic << "\nMEffects = " << ptrizen->MEffects;
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
		return ptrizen;

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
	SetUp* LoadSettings(SetUp &params)
	{
		ptrFile = fopen("settings.ini", "r");

		struct SetUp *ptrizen = &params;
	/*	while (fgets(ptrizen->test, 100, ptrFile) != NULL)
		{
			ptrizen->Xresolution;
			ptrizen->Yresolution;
			ptrizen->FullScreenMode;
			ptrizen->Music;
			ptrizen->Effects;
			ptrizen->MMusic;
			ptrizen->MEffects;
		}
		fclose(ptrFile);*/
		return ptrizen;
	}
};