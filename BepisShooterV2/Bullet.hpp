#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float angle, float speed, float x, float y);
	void Draw(std::shared_ptr<sf::RenderWindow> window);
	void Update();
	sf::Vector2f GetPosition();
	sf::FloatRect GetGlobalBounds();
private:
	sf::Clock deltaTimeClock;
	sf::CircleShape bulletEntity;
	float offsetx;
	float offsety;
	float speed;
};

