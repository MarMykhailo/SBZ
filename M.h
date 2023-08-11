#pragma once
#include <SFML/Graphics.hpp>

//void moveCircleToClick(sf::CircleShape& circle, sf::RenderWindow& window)
//{
//    bool isMoving = false;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//            {
//                isMoving = true;
//                circle.setPosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
//            }
//            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
//                isMoving = false;
//        }
//
//        if (isMoving)
//        {
//            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//            circle.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
//        }
//
//        window.clear();
//        window.draw(circle);
//        window.display();
//    }
//}
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Рух кола до позиції, де клікнуто");
//
//    sf::CircleShape circle(50);
//    circle.setFillColor(sf::Color::Blue);
//    circle.setOrigin(circle.getRadius(), circle.getRadius());
//    circle.setPosition(100, 100);
//
//    moveCircleToClick(circle, window);
//
//    return 0;
//}
