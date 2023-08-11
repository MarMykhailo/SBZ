#include "Map.h"


	int CountEl[8];
	ElMap* ELandscape;
	ElMap* EItem;
	ElMap* ENPC;
	ElMap* EMob;
	Essence** ToDrawLandscape;
	Item** ToDrawItem;
	Essence** ToDrawNPC;
	Essence** ToDrawMob;

	Map::Map()
	{
		CountEl[0] = 0;
		CountEl[1] = 0;
		CountEl[2] = 0;
		CountEl[3] = 0;
		ELandscape = nullptr;
		EItem = nullptr;
		ENPC = nullptr;
		EMob = nullptr;
		ToDrawLandscape = nullptr;
		ToDrawItem = nullptr;
		ToDrawNPC = nullptr;
		ToDrawMob = nullptr;

	}
	Map::~Map()
	{
		DeleteAll();
	}

	void Map::ReadFile(const char* Path, ElMap*& Arr, int n)
	{

		std::ifstream file(Path);
		if (!file)
		{
			std::cerr << "Failed to open file: " << Path << std::endl;

			CountEl[n] = 0;
			return;
		}

		file >> CountEl[n];
		Arr = new ElMap[CountEl[n]];
		for (int i = 0; i < CountEl[n]; ++i)
		{
			file >> Arr[i].x >> Arr[i].y >> Arr[i].Angle >> Arr[i].NumSpecif;

			Arr[i].Specif = new float[Arr[i].NumSpecif];
			for (size_t j = 0; j < Arr[i].NumSpecif; j++)
			{
				file >> Arr[i].Specif[j];
			}
		}
	}

	void Map::SetMap(const char* Path)
	{
		DeleteAll();
		//доробити так щоб додавалися стрічки і отримували шлях
		ReadFile("Source/DB/Maps/StartMap/Landscape.txt", ELandscape, 0);
		ReadFile("Source/DB/Maps/StartMap/Item.txt", EItem, 1);
		

		//ReadFile("Source/DB/Maps/StartMap/NPS.txt", NPC, 2);
		//ReadFile("Source/DB/Maps/StartMap/Mob.txt", Mob, 3);
	}


	void Map::Draw(sf::RenderWindow& Window, Player& Player)
	{
		//перевірка чи наскільки близько перс до обєктів що треба відмалювати допустимо квадрат 2000 на 2000
		//відмальовка 

		
		int j = 0;
		if (!ToDrawLandscape)
		{
			ElMap* MToDrowLandscape = new ElMap[100];

			for (int i = 0; i < CountEl[0]; i++)
			{
				if (abs(ELandscape[i].x - Player.GetPosition().x) < 1500 && abs(ELandscape[i].y - Player.GetPosition().y) < 1500)
				{
					MToDrowLandscape[j] = ELandscape[i];
					j++;
				}
			}
			ToDrawLandscape = MakeLandscape(MToDrowLandscape, j);
			CountEl[4] = j;
			j = 0;
			delete[] MToDrowLandscape;
		}
		if (!ToDrawItem)
		{
			ElMap* MToDrowItem = new ElMap[100];
			for (int i = 0; i < CountEl[1]; i++)
			{

				if (abs(EItem[i].x - Player.GetPosition().x) < 1000 && abs(EItem[i].y - Player.GetPosition().y) < 1000)
				{
					MToDrowItem[j] = EItem[i];
					j++;
				}
			}
			ToDrawItem = MakeItem(MToDrowItem, j);
			CountEl[5] = j;

			j = 0;
			delete[] MToDrowItem;
		}
		if (!ToDrawNPC)
		{
			ElMap* MToDrowNPC = new ElMap[100];
			for (int i = 0; i < CountEl[2]; i++)
			{
				if (abs(ENPC[i].x - Player.GetPosition().x) < 1000 && abs(ENPC[i].y - Player.GetPosition().y) < 1000)
				{
					MToDrowNPC[j] = ENPC[i];
					j++;
				}
			}
			ToDrawNPC = MakeNPC(MToDrowNPC, j);
			CountEl[6] = j;
			j = 0;
			delete[] MToDrowNPC;
		}
		if (!ToDrawMob)
		{
			ElMap* MToDrowMob = new ElMap[100];
			for (int i = 0; i < CountEl[3]; i++)
			{
				if (abs(EMob[i].x - Player.GetPosition().x) < 1000 && abs(EMob[i].y - Player.GetPosition().y) < 1000)
				{
					MToDrowMob[j] = EMob[i];
					j++;
				}
			}
			ToDrawMob = MakeMob(MToDrowMob, j);
			CountEl[7] = j;
			j = 0;
			delete[] MToDrowMob;
		}
		DrawLandscape(Window, Player);

		DrawItem(Window, Player);
		
		//DrawNPC(Window, Player);
		//DrawMob(Window, Player);


	}

	Essence** Map::MakeLandscape(ElMap* El, int n)
	{

		Essence** ToDrow = new Essence * [n];
		for (int i = 0; i < n; i++)
		{
			if (El[i].Specif[0] == 1)
			{
				//трава
				ToDrow[i] = new Essence;
				ToDrow[i]->SetSprite(1, "Assets/Sprites/Textures/Grass.png");
				ToDrow[i]->SetPosition(El[i].x, El[i].y);
			}
			if (El[i].Specif[0] == 2)
			{

				//дерево
				ToDrow[i] = new Essence;
				ToDrow[i]->SetSprite(1, "Assets/Sprites/Textures/Tree.png");
				ToDrow[i]->SetRotation(El[i].Angle);
				ToDrow[i]->SetPosition(El[i].x, El[i].y);
			}
			if (El[i].Specif[0] == 3)
			{

				//Дорога
				ToDrow[i] = new Essence;
				ToDrow[i]->SetSprite(1, "Assets/Sprites/Textures/Road.png");
				ToDrow[i]->SetRotation(El[i].Angle);
				ToDrow[i]->SetPosition(El[i].x, El[i].y);
			}
		}
		return ToDrow;
	}	
	Item** Map::MakeItem(ElMap* El, int n)
	{
		Item** ToDrow = new Item * [n];
		for (int i = 0; i < n; i++)
		{
			if (El[i].Specif[0] == 1)
			{
				//яблуко
				ToDrow[i] = new Item;
				ToDrow[i]->SetSprite(1, "Assets/Sprites/Item/Apple.png");
				ToDrow[i]->SetPosition(El[i].x, El[i].y);
				ToDrow[i]->SetScale(El[i].Specif[1], El[i].Specif[2]);
			}
		}
		return ToDrow;
	}
	Essence** Map::MakeNPC(ElMap* El, int n)
	{
		//NPC** ToDrow = new NPC * [n];
		//for (int i = 0; i < n; i++)
		//{
		//	if (El[i].Specif[0] == 1)
		//	{
		//		//яблуко
		//		ToDrow[i] = new NPC;
		//		ToDrow[i]->SetSprite(1, "Assets/Sprites/NPC/Apple.png");
		//		ToDrow[i]->SetPosition(El[i].x, El[i].y);
		//		ToDrow[i]->SetScale(El[i].Specif[1], El[i].Specif[2]);
		//	}
		//}
		/*return ToDrow;*/
		return nullptr;
	}
	Essence** Map::MakeMob(ElMap* El, int n)
	{
		//Mob** ToDrow = new Mob * [n];
		//for (int i = 0; i < n; i++)
		//{
		//	if (El[i].Specif[0] == 1)
		//	{
		//		//яблуко
		//		ToDrow[i] = new Mob;
		//		ToDrow[i]->SetSprite(1, "Assets/Sprites/Mob/Apple.png");
		//		ToDrow[i]->SetPosition(El[i].x, El[i].y);
		//		ToDrow[i]->SetScale(El[i].Specif[1], El[i].Specif[2]);
		//	}
		//}
		//return ToDrow;
		return nullptr;
	}

	
	

	void Map::DrawLandscape(sf::RenderWindow& Window, Player& Player)
	{
		for (int i = 0; i < CountEl[4]; i++)
		{
			ToDrawLandscape[i]->Draw(Window);
		}
	}
	void Map::DrawItem(sf::RenderWindow& Window, Player& Player)
	{

		
		for (int i = 0; i < CountEl[5]; i++)
		{

			if (ToDrawItem[i] != nullptr)
			{
				
				ToDrawItem[i]->Draw(Window);
				
			}
		}
		

	}
	void Map::DrawNPC(sf::RenderWindow& Window, Player& Player)
	{

	}
	void Map::DrawMob(sf::RenderWindow& Window, Player& Player)
	{
		//кожен раз перемальовую
	}

	void Map::DeleteEssence(Essence** ToDrowEssence, ElMap* ToDrow, int j)
	{
		for (int i = 0; i < j; i++)
		{
			delete ToDrowEssence[i];
		}
		delete[] ToDrowEssence;
		delete[] ToDrow;
	}
	void Map::DeleteAll()
	{
		if (ELandscape)
			delete[] ELandscape;
		if (EItem)
			delete[] EItem;
		if (ENPC)
			delete[] ENPC;
		if (EMob)
			delete[] EMob;
		if (ToDrawLandscape)
		{
			for (int i = 0; i < CountEl[5]; i++)
			{
				delete ToDrawLandscape[i];
			}
		}
		if (ToDrawItem)
		{
			for (int i = 0; i < CountEl[1]; i++)
			{
				delete ToDrawItem[i];
			}
		}
		if (ToDrawNPC)
		{
			for (int i = 0; i < CountEl[2]; i++)
			{
				delete ToDrawNPC[i];
			}
		}
		if (ToDrawMob)
		{
			for (int i = 0; i < CountEl[3]; i++)
			{
				delete ToDrawMob[i];
			}
		}


	}
