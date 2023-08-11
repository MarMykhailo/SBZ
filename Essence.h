

#pragma once
#include <SFML/Graphics.hpp>

#include "GlobalSprite.h"
#include <string>
#include <vector>

class Essence
{
protected:
	


	
public:
	GeneralSprite GSprite;



	Essence() 
	{ 
		GSprite.n = 0;
		GSprite.NSprite = nullptr;
	}
	Essence(int n, const char* Path, ...)
	{
		GSprite.SetGSprite(n, Path);
		GSprite.SetScale(0.25, 0.25);
	}
	~Essence()
	{

		
		
	}
	void SetSprite(int n ,const char* Path,...)
	{

		GSprite.SetGSprite(n, Path);
		
		sf::Vector2u spriteSize = GSprite.NSprite[0].Texture.getSize();
			
		GSprite.NSprite[0].Sprite.setOrigin(spriteSize.x / 2, spriteSize.y / 2);	
	}

	void Draw(sf::RenderWindow& window)
	{
		GSprite.Draw(window);
	}
	void SetPosition(float x, float y)
	{
		GSprite.NSprite[0].Sprite.setPosition(x, y);
	}
	void SetScale(float x, float y)
	{
		for (int i = 0; i < GSprite.n; i++)
		{
			GSprite.NSprite[i].Sprite.setScale(x, y);
		}
		
	}
	void SetRotation(float angle)
	{
		for (int i = 0; i < GSprite.n; i++)
		{
			GSprite.NSprite[0].Sprite.setRotation(angle);
		}
	}
	GeneralSprite GetSprite()
	{
		return GSprite;
	}
	
	sf::Vector2f GetPosition()
	{
		return GSprite.NSprite[0].Sprite.getPosition();
	}
	
	virtual Essence& operator=(const Essence& other)
	{
		GSprite = other.GSprite;
		return *this;
	}
	
	



	// Решта методів та геттерів/сеттерів
};


