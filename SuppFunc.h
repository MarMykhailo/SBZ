#pragma once

#include <SFML/Graphics.hpp>

float GetDistanceBetweenSprite(sf::Sprite& Sp1, sf::Sprite& Sp2)
{

	return sqrt(pow(Sp1.getPosition().x - Sp2.getPosition().x, 2) + pow(Sp1.getPosition().y - Sp2.getPosition().y, 2));
}