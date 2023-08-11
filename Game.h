#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"




class Game
{
protected:
	sf::RenderWindow Window;
	sf::View Camera;
	sf::Clock Clock;
	Map Map;//позиція ,тип обєкта

public:
	Game()
	{
		//Window.create(sf::VideoMode(900, 800), "SBZ");
		//Window.create(sf::VideoMode::getDesktopMode(), "SBZ", sf::Style::Fullscreen);
		Window.create(sf::VideoMode::getDesktopMode(), L"Виживалка", sf::Style::Fullscreen);
		Window.setVerticalSyncEnabled(true);		//Window.setFramerateLimit(60);
	};

	~Game()
	{

	}

	void Run()
	{
		
		Player Player(&Map);
		Player.camera = &Camera;
		Essence  Apple;
		Apple.SetSprite(1, "Assets/Sprites/Item/Apple.png");
		Map.SetMap("Assets/Maps/StartMap");


		
		while (Window.isOpen())
		{
			float time = Clock.getElapsedTime().asMicroseconds();
			Clock.restart();
			time = time / 800;
			sf::Event event;
			while (Window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					Window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					Window.close();
			}

			Player.Do(&Window);

			
			Window.clear();
			Window.setView(Camera);
			Map.Draw(Window, Player);
			
			//Apple.Draw(Window);
			Player.Draw(Window);
			
			Window.display();

		}

	}




};