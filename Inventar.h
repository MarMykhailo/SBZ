#pragma once
#include <fstream>
#include "GlobalSprite.h"
#include "Item.h"



class ElInventory
{
public:
	int Type;
	int CountSp;
	float* Specif;

	ElInventory()
	{}
	~ElInventory()
	{
		if (Specif)
		{
			delete[] Specif;
		}
	}
};



class Inventory
{
public:
	GeneralSprite GSInventory;
	ElInventory* ElItems;
	Item** IItems;

	int CountEl;
	float GMass;
	float GVolume;
	int  GBracing;//кріплення для предметів ззовніречей

	Inventory() :CountEl(0), ElItems(nullptr), IItems(nullptr)
	{
		IItems = new Item * [10] {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
		CountEl = 10;

		//зчитати з файла 
	}
	~Inventory()
	{
		//записую у файл речі з інвентаря

		delete[] ElItems;
		delete[] IItems;
	}

	void SetInventory()
	{
		GSInventory.SetGSprite(3, "Assets/Sprites/Inventory/Inventory.png", "Assets/Sprites/Inventory/Inventory.png", "Assets/Sprites/Inventory/Sekect.png");
		GSInventory.NSprite[0].Sprite.setScale(1.28, 1.28);
		GSInventory.NSprite[1].Sprite.setScale(1.25, 1.25);
		GSInventory.NSprite[2].Sprite.setScale(0.25, 0.25);
		GSInventory.SetPosition(100, 100);
	}

	void Draw(sf::RenderWindow& window, sf::Vector2f position)//доробити щоб відмальовувалися не вісі речі а лише ті що поміщаються в інвентарі ну або ті на які прокрутили 
	{
		GSInventory.NSprite[0].Sprite.setPosition(position.x + 600, position.y - 200);
		GSInventory.NSprite[1].Sprite.setPosition(position.x + 600, position.y - 200);

		GSInventory.NSprite[0].Draw(window);
		GSInventory.NSprite[1].Draw(window);
		DrawInventory(window, position);
		MoveSelect(position, window);
	}


	void DrawInventory(sf::RenderWindow& window, sf::Vector2f position)
	{
		// Змінна ItemCount вказує на кількість речей для відображення

		position.x += 287.5 + 62.5;
		position.y += -512.5 + 62.5;
		float xOffset = 125.0f; // Зміщення по X для розташування речей поруч
		float yOffset = 0; // Зміщення по Y для розташування речей поруч


		for (int i = 0; i < CountEl; i++)
		{
			if (IItems[i] != nullptr) // Перевірка, чи є річ в позиції інвентаря
			{
				// Задати позицію речі з інвентаря
				IItems[i]->SetPosition(position.x + xOffset * i, position.y + yOffset);

				// Задати масштаб 0.25x0.25
				IItems[i]->SetScale(0.25f, 0.25f);

				// Відобразити річ на вікні
				IItems[i]->Draw(window);
			}
			if (i % 5 == 0 && i != 0)
			{
				yOffset += 125.0f;
			}
		}
	}



	void MoveSelect(sf::Vector2f PosPlayer, sf::RenderWindow& window)
	{
		sf::Vector2i MousePosition = sf::Mouse::getPosition(window);

		if (IsMouseInBox(PosPlayer, MousePosition, window))
		{
			sf::Vector2f MouseWorldPos = window.mapPixelToCoords(MousePosition);
			sf::Vector2f InventoryTopLeft = sf::Vector2f(PosPlayer.x + 287.5, PosPlayer.y - 512.5);

			int i = std::abs(MouseWorldPos.x - InventoryTopLeft.x) / 125 + 1;
			int j = std::abs(MouseWorldPos.y - InventoryTopLeft.y) / 125 + 1;
			//std::cout << j << " " << i << std::endl;

			int x = i * 125 - 62.5 + InventoryTopLeft.x;
			int y = j * 125 - 62.5 + InventoryTopLeft.y;
			
			GSInventory.NSprite[2].Sprite.setPosition(x, y);
			GSInventory.NSprite[2].Draw(window);
		}
	}


	bool IsMouseInBox(sf::Vector2f PosPlayer, sf::Vector2i PosMouse, sf::RenderWindow& window)
	{
		// Перетворення координат миші на координати світу (відносно вікна)
		sf::Vector2f mouseWorldPos = window.mapPixelToCoords(PosMouse);
		return mouseWorldPos.x >= PosPlayer.x + 287.5f && mouseWorldPos.x <= PosPlayer.x + 912.5f && mouseWorldPos.y <= PosPlayer.y + 112.5f && mouseWorldPos.y >= PosPlayer.y - 512.5f;
	}

	
	void InFile(const char* Path)
	{

		std::ifstream file;
		file.open(Path);
		file >> CountEl;
		ElItems = new ElInventory[CountEl];
		for (int i = 0; i < CountEl; ++i)
		{
			file >> ElItems[i].Type >> ElItems[i].CountSp;
			ElItems[i].Specif = new float[ElItems[i].CountSp];

			for (size_t j = 0; j < ElItems[i].CountSp; j++)
			{
				file >> ElItems[i].Specif[j];
			}
		}
	}

	void OutFile(const char* Path)
	{
		//оцищення файла

		std::ofstream fout;
		fout.open(Path);
		fout << CountEl << std::endl;
		for (int i = 0; i < CountEl; i++)
		{
			IItems[i]->OutFile(fout);
		}
	}

	
	void AddItem(Item* Element)
	{
		for (int i = 0; i < CountEl; i++)
		{
			if (IItems[i] == nullptr)
			{
				IItems[i] = Element;
				break;
			}
		}
	}



};


