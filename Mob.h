#pragma once
#include "Essence.h"
class Mob : public Essence
{
protected:
	float Spead;
	float Health;
	float Strength;
	float Dmage;
	float Armor;
	float Stamina;
	float Hunger;
	float Thirst;	
	sf::Sprite VisibilityArea;	
	float Hearing;
	float Vision;
	float Smell;
	
	
public:
	Mob() {};
	Mob(int n,const char* Path) :Spead(0), Health(0), Strength(0), Armor(0), Stamina(0), Hunger(0), Thirst(0)
	{	
		SetSprite(n,Path);
	}
	virtual void Mind(sf::Clock)
	{
		//перевірка що бачить моб
		//перевірка чи є вороги
		//перевірка чи є їжа
		//перевірка чи є вода
	}
	virtual void Move(sf::Clock)
	{

	}
	

	
	
#pragma region Seters/Geters
	void SetSpeed(float Speed)
	{
		this->Spead = Speed;
	}
	float GetSpeed()
	{
		return Spead;
	}
	void SetHealth(float Health)
	{
		this->Health = Health;
	}
	float GetHealth()
	{
		return Health;
	}
	void SetStrength(float Strength)
	{
		this->Strength = Strength;
	}
	float GetStrength()
	{
		return Strength;
	}
	void SetArmor(float Armor)
	{
		this->Armor = Armor;
	}
	float GetArmor()
	{
		return Armor;
	}
	void SetStamina(float Stamina)
	{
		this->Stamina = Stamina;
	}
	float GetStamina()
	{
		return Stamina;
	}
	void SetHunger(float Hunger)
	{
		this->Hunger = Hunger;
	}
	float GetHunger()
	{
		return Hunger;
	}
	void SetThirst(float Thirst)
	{
		this->Thirst = Thirst;
	}
	float GetThirst()
	{
		return Thirst;
	}
#pragma endregion
	
};

