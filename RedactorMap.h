#pragma once
#include <stdarg.h>
#include <fstream>





class RedactorMap
{
public:
	int n;
	const char** Path;


	RedactorMap() {};

	RedactorMap(int n, const char* Path, ...)
	{
		this->n = n;
		this->Path = new const char* [n];

		va_list args;
		va_start(args, Path);
		for (int i = 0; i < n; i++)
		{
			this->Path[i] = Path;
			Path = va_arg(args, const char*);
		}
		va_end(args);
	}

	~RedactorMap()
	{
		delete[] Path;
	}
	//заповнення текстурою файл у вигляді квадрати  із заданими координатами
	void MakeMap(const char* Path, int x1, int y1, int x2, int y2)
	{
		std::ofstream fout(Path);
		//підрахунок кількості спрайтів у файлі
		int n = 0;
		for (int i = x1; i < x2; i += +400)
		{
			for (int j = y1; j < y2; j += +400)
			{
				n++;
			}
		}
		//запис кількості спрайтів у файл
		fout << n << std::endl;
		//текстура розміром 400 на 400
		for (int i = x1; i < x2; i +=  400)
		{
			for (int j = y1; j < y2; j +=  400)
			{
				//заповнення текстурою файл у вигляді квадрати  із заданими координатами
				fout << i << " " << j << " " << 0 << " " << 1 << " " << 1 << std::endl;
			}
		}
	}










};