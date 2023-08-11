#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Test
{
public:
	Test() {};
	~Test() 
	{
		delete Sprite;
	}
	sf::Sprite* Sprite;
	
	void SetSprite(std::string path)
	{
		delete Sprite;
		sf::Texture texture;
		if (!texture.loadFromFile(path))
		{

		}
		Sprite = new sf::Sprite;

		Sprite->setTexture(texture);
		sf::Vector2u spriteSize = texture.getSize();
		Sprite->setOrigin(spriteSize.x / 2, spriteSize.y / 2);

	}
	void Draw(sf::RenderWindow& window)
	{
		window.draw(*Sprite);
	}
};

