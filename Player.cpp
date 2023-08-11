#include "Player.h"



Player::Player()
{
    Spead = 10.0f;
    GSprite.SetGSprite(1, "Assets/Sprites/Characters/Player.png");
    //Inventar.SetInventory();
    IsPressedEvent = false;
    IsInventoryOpen = false;
}

Player::Player(Map* MMap)
{
    this->MMap = MMap;
    Spead = 1.0f;
    GSprite.SetGSprite(1, "Assets/Sprites/Characters/Player.png");
    Inventar.SetInventory();
    IsPressedEvent = false;
    IsInventoryOpen = false;
}

Player::Player(int n, const char* Path, ...)
{

    //SetSprite(n, Path);
    //GSprite.NSprite[0].Sprite.setScale(0.5f, 0.5f);
//      GSprite.NSprite[0].Sprite.setPosition(100, 100);
      //Spead = 0.5f;  //Sprite.setRotation(GetRotationAngle(spritePosition, sf::Vector2f(mousePosition.x, mousePosition.y)));
//     
}
Player::~Player()
{
    delete[] GSprite.NSprite;
    Inventar.OutFile("Source/DB/Player/Inventory.txt");
    delete[] Indecators;

}

void Player::ZoomCamera(sf::RenderWindow* window)
    {
        sf::Event event; // Ініціалізуємо змінну event тут
        while (window->pollEvent(event)) // Зчитуємо всі доступні події з вікна
        {
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                camera->setSize(window->getSize().x, window->getSize().y);

                sf::Vector2f characterPosition = GSprite.NSprite[0].Sprite.getPosition();
                camera->setCenter(characterPosition);
                if (event.mouseWheelScroll.delta > 0) // Прокрутка вперед
                {
                    Zoom = Zoom > 5.0f || Zoom < 1.0f ? Zoom + 0.01f : Zoom;

                    camera->zoom(Zoom); // Зближення камери
                }
                else if (event.mouseWheelScroll.delta < 0) // Прокрутка назад
                {
                    Zoom = Zoom > 5.0f || Zoom < 1.0f ? Zoom - 0.01f : Zoom;

                    camera->zoom(Zoom); // Віддалення камери
                }
            }
        }
    }
    //робичо так щоб коли персонаж наближався до краю екрану то камера починала рухатися в ту сторону
void Player::MoveCamera(sf::RenderWindow& window, sf::Vector2f XY)
    {
        camera->setSize(window.getSize().x, window.getSize().y);
        sf::Vector2f characterPosition = GSprite.NSprite[0].Sprite.getPosition();
        camera->setCenter(characterPosition);

        // window.setView(*camera);
    }
float Player::GetRotationAngle(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition)
    {
        sf::Vector2f direction = targetPosition - objectPosition;
        const float pi = 3.14159265358979323846;
        return std::atan2(direction.y, direction.x) * 180 / pi + 90;
    }
float Player::GetDistanceFromSpriteToMouse(const sf::Sprite& sprite, const sf::RenderWindow& window)
    {
        sf::Vector2f spritePosition = sprite.getPosition();
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        // Перетворення позиції мишки з вікна в координати відносно спрайта
        sf::Vector2f transformedMousePosition = window.mapPixelToCoords(mousePosition);

        // Обчислення відстані за допомогою теореми Піфагора
        float dx = transformedMousePosition.x - spritePosition.x;
        float dy = transformedMousePosition.y - spritePosition.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        return distance;
    }
void Player::Move(sf::RenderWindow* window)
{
    float spead = Spead;
    //перевірка що натиснуто
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))//бігти
    {
        IsPressedShift = true;
        IsPressedControl = false;
        //Run();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))//присісти
    {
        IsPressedShift = false;
        IsPressedControl = true;
        //Crouch();//присісти

    }

    //Valk();
   
    

        



    // Отримати розмір вікна
    sf::Vector2u windowSize = window->getSize();

    // Отримати позицію курсора миші
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    // Обчислити вектор напрямку від центру екрана до курсора миші
    sf::Vector2f direction = sf::Vector2f(mousePosition.x, mousePosition.y) - sf::Vector2f(windowSize.x / 2, windowSize.y / 2);
    const float pi = 3.14159265358979323846;
    // Обчислити кут обертання спрайту
    float rotation = std::atan2(direction.y, direction.x) * 180 / pi + 90;
    GSprite.SetRotation(rotation);
    
    // Обчислити вектор швидкості руху спрайту
    sf::Vector2f velocity;
    if (GetDistanceFromSpriteToMouse(GSprite.NSprite[0].Sprite, *window) > 100)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            velocity = direction; // Рух вздовж уявної лінії до курсора
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sf::Vector2f perpendicular(-direction.y, direction.x); // Вектор перпендикулярний до уявної лінії
            velocity -= perpendicular; // Рух вліво відносно уявної лінії
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            velocity = -direction; // Рух вздовж уявної лінії від курсора до спрайта
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sf::Vector2f perpendicular(direction.y, -direction.x); // Вектор перпендикулярний до уявної лінії
            velocity -= perpendicular; // Рух вправо відносно уявної лінії
        }

        // Нормалізувати вектор швидкості, щоб забезпечити рух з однаковою швидкістю в будь-якому напрямку
        if (std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y) > 1)
        {
            velocity = velocity / std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        }

        // Застосувати швидкість до руху спрайту
        GSprite.Move(velocity * Spead);
        MoveCamera(*window, velocity * Spead);
    }



}

void Player::Take()
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        for (int i = 0; i < MMap->CountEl[5]; i++)
        {
            if (MMap->ToDrawItem[i] != nullptr)
            {
                float k = GetDistanceBetweenSprite(GSprite.NSprite[0].Sprite, MMap->ToDrawItem[i]->GSprite.NSprite[0].Sprite);

                if (k < 100.0f)
                {
                    Inventar.AddItem(MMap->ToDrawItem[i]);
                    MMap->ToDrawItem[i] = NULL;

                    break;
                }
            }
        }
    }
    
}
    
void Player::DrawInventar(sf::RenderWindow& Window)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && !IsPressedEvent)
        {
            IsInventoryOpen = !IsInventoryOpen;
            IsPressedEvent = true;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            IsPressedEvent = false;
        }

        if (IsInventoryOpen)
        {
             Inventar.Draw( Window,GetPosition());
        }
    }
    
void Player::Do(sf::RenderWindow* window)
{
    
    Move(window);

    //взяти 
    
    Take();
    //покласти
    //взаємодія

    //ZoomCamera(window);

}
    
float Player::GetDistanceBetweenSprite(sf::Sprite& Sp1, sf::Sprite& Sp2)
    {
        float distance = sqrt(pow(Sp1.getPosition().x - Sp2.getPosition().x, 2) + pow(Sp1.getPosition().y - Sp2.getPosition().y, 2));

        return distance;
    }
    
    // інвентар (двовимірний масив інтів для окжного зберігається вага і обєм і кількість загальна бо можна знайти одну за  )
    // 
    // спеціальні можливості(біг стрибок ) пригнутися  повзти

void Player::Draw(sf::RenderWindow& window)
{
    GSprite.Draw(window);
    DrawInventar(window);
}
    