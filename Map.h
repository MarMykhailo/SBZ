
#ifndef MAP_H
#define MAP_H

#include "Player.h"
#include "Item.h"
#include "ElMap.h"
#include <cmath>
#include <iostream>
#include <fstream>






class Player;

class Map
{

protected:



	
public:
	int CountEl[8];
	ElMap* ELandscape;
	ElMap* EItem;
	ElMap* ENPC;
	ElMap* EMob; 
	Essence** ToDrawLandscape;
	Item** ToDrawItem;
	Essence** ToDrawNPC;
	Essence** ToDrawMob;
	
	Map();
	~Map();
	
	void ReadFile(const char* Path, ElMap*& Arr, int n);

	void SetMap(const char* Path);
	

	void Draw(sf::RenderWindow& Window, Player& Player);
	
	Essence** MakeLandscape(ElMap* El, int n);
	Essence** MakeNPC(ElMap* El, int n);
	Essence** MakeMob(ElMap* El, int n);
	Item** MakeItem(ElMap* El, int n);


	void DrawLandscape(sf::RenderWindow& Window, Player& Player);
	void DrawItem(sf::RenderWindow& Window, Player& Player);
	void DrawNPC(sf::RenderWindow& Window, Player& Player);
	void DrawMob(sf::RenderWindow& Window, Player& Player);
		
	void DeleteEssence(Essence** ToDrowEssence, ElMap* ToDrow, int j);
	void DeleteAll();
	
};

#endif // !MAP_H
//void FillTexture(GeneralSprite* gras, int size)
	//{
	//	for (int i = 0; i < size; ++i)
	//	{
	//		gras[i].SetGSprite(1, "Assets/Sprites/Textures/Grass.png");
	//		gras[i].SetPosition(sf::Vector2f(-1000 + (i % 10) * 400, -1000 + (i / 10) * 400));
	//		gras[i].SetScale(sf::Vector2f(1.0f, 1.0f)); // Налаштуйте потрібний масштаб
	//	}
	//}
