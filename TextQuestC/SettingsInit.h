#pragma once
#include <fstream>
#include <sstream>
using namespace std;
class SettingsInit
{
public:
	//typedef struct __attribute__((__packed__))  - Пакованная машинно-независимая структура
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
		const int len = 30, strings = 5;
		const char ch = '\n';
		char mass[len][strings];

		ifstream fs("settings.txt", ios::in | ios::binary);

		for (int r = 0; r<strings; r++)
		{
			fs.getline(mass[r], len - 1, ch); //Считываем строки в массив
			mass[r]; //Выводи строку из массива
		}
		fs.close(); //Закрываем файл


		//ptrFile = fopen("settings.ini", "r");
		vector<string> arr;
		ifstream ifs;
		ifs.open("settings.ini");
		while (!ifs.eof()) {

			string str;
			string delim("= ");
			size_t prev = 0;
			size_t next;
			size_t delta = delim.length();


			getline(ifs, str);

			if ((next = str.find(delim, prev)) != string::npos)
			{
				prev = next + prev + 2;
				string tmp = str.substr(prev);
				arr.push_back(tmp);
			}

		}

		ifs.close();
		struct SetUp *ptrizen = &params;
		ptrizen->Xresolution = stoi(arr[0]);
		ptrizen->Yresolution = stoi(arr[1]) ;
		ptrizen->FullScreenMode = stoi(arr[2]);
		ptrizen->Music =stoi(arr[3]);
		ptrizen->Effects=stoi(arr[4]);
		ptrizen->MMusic=stoi(arr[5]);
		ptrizen->MEffects=stoi(arr[6]);
		//fclose(ptrFile);
		return ptrizen;
		//123
	}
};