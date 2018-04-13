#pragma once
#include <fstream>
#include <sstream>
using namespace std;
class SettingsInit
{
public:
	//typedef struct __attribute__((__packed__))  - Пакованная машинно-независимая структура
	struct SetUp {
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

		ptrFile = fopen("settings.ini", "w");
		struct SetUp *ptrizen = &params;

		/// <summary>
		/// [Optimal]Resolution
		/// </summary>



		//[VIDEO]
		ptrizen->FullScreenMode = false;
		//[AUDIO]
		ptrizen->Music = 30;
		ptrizen->Effects = 11;
		ptrizen->MMusic = true;
		ptrizen->MEffects = false;

		///END


		stringstream ParsW, ParsA;
		string str;
		const char *s1;
		ParsW << "[Settings]\nFullScreenMode = " << ptrizen->FullScreenMode;
		str = ParsW.str();
		s1 = str.c_str();
		fputs(s1, ptrFile);
		ParsA << "\nMusic = " << ptrizen->Music << "\nEffects = " << ptrizen->Effects << "\nMMusic = " << ptrizen->MMusic << "\nMEffects = " << ptrizen->MEffects;
		str = ParsA.str();
		s1 = str.c_str();
		fputs(s1, ptrFile);
		fclose(ptrFile);
		return ptrizen;

	}
	void UpdateSettings(SetUp &params)
	{
		ptrFile = fopen("settings.ini", "w");
		struct SetUp *ptrizen = &params;

		stringstream ParsW, ParsA;
		string str;
		const char *s1;
		ParsW << "[Settings]\nFullScreenMode = " << ptrizen->FullScreenMode;
		str = ParsW.str();
		s1 = str.c_str();
		fputs(s1, ptrFile);
		ParsA << "\nMusic = " << ptrizen->Music << "\nEffects = " << ptrizen->Effects << "\nMMusic = " << ptrizen->MMusic << "\nMEffects = " << ptrizen->MEffects;
		str = ParsA.str();
		s1 = str.c_str();
		fputs(s1, ptrFile);
		fclose(ptrFile);

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
		ptrizen->FullScreenMode = stoi(arr[0]);
		ptrizen->Music =stoi(arr[1]);
		ptrizen->Effects=stoi(arr[2]);
		ptrizen->MMusic=stoi(arr[3]);
		ptrizen->MEffects=stoi(arr[4]);
		//fclose(ptrFile);
		return ptrizen;
		//123
	}
};