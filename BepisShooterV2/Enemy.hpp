#pragma once
#include <SFML/Graphics.hpp>

enum EntityState {
	Alive,
	Dead
};

class Enemy
{
public:
	Enemy();
	Enemy(float maxHP);
	void Update();
	void Draw(std::shared_ptr<sf::RenderWindow> window);
	void Hit(float damage);
	sf::FloatRect GetHitbox();
	EntityState EntityState;
private:
	sf::Clock attackTimer;
	const float maxHP;
	float HP;
	sf::RectangleShape enemyEntity;
};

