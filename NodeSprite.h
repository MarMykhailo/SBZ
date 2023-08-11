#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class NodeSprite
{
public:
	const char* Name;
	sf::Image Image;
	sf::Texture Texture;
	sf::Sprite Sprite;

	NodeSprite() {};
	NodeSprite(const char* Path)
	{
		SetSprite(Path);
	}
	void SetSprite(const char* Path)
	{
		Name = Path;
		Image.loadFromFile(Path);
		Texture.loadFromImage(Image);
		Sprite.setTexture(Texture);
		sf::Vector2u spriteSize = Texture.getSize();
		Sprite.setOrigin(spriteSize.x / 2, spriteSize.y / 2);
	}
	void Draw(sf::RenderWindow& window)
	{
		window.draw(Sprite);
	}




};

