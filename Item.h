#pragma once

#include <fstream>
#include "Essence.h"
class Item :  public Essence
{
public:
	int Type;//1 їжа 2 зброя 3 одяг 4 медикаменти
	float Mass;
	float Volume;
	int Position;//позиція в інвентарі
	bool isEquip;//чи є надітий предмет/взятий у руки


	
	Item() {};
	~Item() {};
	

	void OutFile(std::ofstream& fout)
	{
		fout << Mass << " " << Volume << " " << isEquip << std::endl;
	}
	void InFile(std::ifstream& fin)
	{
		fin >> Mass >> Volume >> isEquip;
	}
	Item& operator = (Item& Other)
	{

		Mass = Other.Mass;
		Volume = Other.Volume;
		Position = Other.Position;
		isEquip = Other.isEquip;
		return *this;
		
	}
};

