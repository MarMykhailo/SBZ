#pragma once
#include "NodeSprite.h"
#include <stdarg.h>
#include <iostream>



class GeneralSprite
{
public:
	int n;
	NodeSprite* NSprite;
	
	GeneralSprite() {};
	

	GeneralSprite(int n, const char* Path, ...)
	{
		this->n = n;
		NSprite = new NodeSprite[n];

		va_list args;
		va_start(args, Path);
		for (int i = 0; i < n; i++)
		{
			NSprite[i].SetSprite(Path);
			NSprite[i].Sprite.setPosition(100 * i, 100 * i);
			Path = va_arg(args, const char*);
		}
		va_end(args);
	}
	GeneralSprite(GeneralSprite& GS)
	{
		this->n = GS.n;
		NSprite = new NodeSprite[n];
		for (int i = 0; i < n; i++)
		{
			NSprite[i] = GS.NSprite[i];
		}
	}
	
	~GeneralSprite()
	{
		delete[] NSprite;
	}
	void SetGSprite(int n, const char* Path, ...)
	{
		this->n = n;
		NSprite = new NodeSprite[n];

		va_list args;
		va_start(args, Path);
		for (int i = 0; i < n; i++)
		{ 
			NSprite[i].SetSprite(Path);
			NSprite[i].Sprite.setPosition(100 * i, 100 * i);
			Path = va_arg(args, const char*);
		}
		va_end(args);
	}
	
	void Move(sf::Vector2f Scale)
	{
		for (int i = 0; i < n; i++)
		{
			sf::Vector2f Scale2 = Scale;
			NSprite[i].Sprite.move(Scale2);
		}
	}
	
	void Draw(sf::RenderWindow& window)
	{
		for (int i = 0; i < n; i++)
		{
			NSprite[i].Draw(window);
		}
	}
	
	
	void SetScale(float x, float y)
	{
		for (int i = 0; i < n; i++)
		{
			NSprite[i].Sprite.setScale(x, y);
		}
	}
	void SetScale(sf::Vector2f scale)
	{
		for (int i = 0; i < n; i++)
		{
			NSprite[i].Sprite.setScale(scale);
		}
	}
	void SetRotation(float angle)
	{
		for (int i = 0; i < n; i++)
		{
			NSprite[i].Sprite.setRotation(angle);
		}
	}
	

	void SetPosition(int x, int y)
	{
		for (int i = 0; i < n; i++)
		{
			NSprite[i].Sprite.setPosition(x, y);
		}
	}
	void SetPosition(sf::Vector2f pos)
	{
		for (int i = 0; i < n; i++)
		{
			NSprite[i].Sprite.setPosition(pos);
		}
	}
	
};





