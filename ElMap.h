#pragma once


class ElMap
{
public:
	float x;
	float y;
	int Angle;
	int NumSpecif;
	float* Specif;
	ElMap()
	{
		x = 0;
		y = 0;
		Angle = 0;
		NumSpecif = 0;
		Specif = nullptr;
	}
	~ElMap()
	{
		if (Specif != nullptr)
		{
			delete[] Specif;
		}
	}
};