#ifndef PLAYER_H
#define PLAYER_H

#include "Mob.h"
#include "Inventar.h"
//#include "SuppFunc.h"
#include "Map.h"
#include <cmath>


class Map;

class Player :public Mob
{
    
protected:
    
	Map* MMap;
    Inventory Inventar;
	int** Indecators;
    float Zoom;

    bool IsPressedEvent;
    bool IsInventoryOpen;
    bool IsPressedShift;
    bool IsPressedControl;
public:
    sf::View* camera;

    Player();
    
    Player(Map* MMap);

    Player(int n, const char* Path, ...);
    ~Player();
    void Mind() = delete;
    void ZoomCamera(sf::RenderWindow* window);


	//робичо так щоб коли персонаж наближався до краю екрану то камера починала рухатися в ту сторону
    void MoveCamera(sf::RenderWindow& window, sf::Vector2f XY);

    
    
    float GetRotationAngle(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition);
	

    float GetDistanceFromSpriteToMouse(const sf::Sprite& sprite, const sf::RenderWindow& window);  
    void Move(sf::RenderWindow* window);
    void Take();

    void DrawInventar(sf::RenderWindow& Window); 
    void Do(sf::RenderWindow* window);
    float GetDistanceBetweenSprite(sf::Sprite& Sp1, sf::Sprite& Sp2);
	// інвентар (двовимірний масив інтів для окжного зберігається вага і обєм і кількість загальна бо можна знайти одну за  )
	// 
	// спеціальні можливості(біг стрибок ) пригнутися  повзти

    void Draw(sf::RenderWindow& window);
    Player& operator = (Player& Other) = delete;
};

#endif // !PLAYER_H