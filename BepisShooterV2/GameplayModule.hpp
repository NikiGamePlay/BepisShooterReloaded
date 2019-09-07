#pragma once
#include "Module.hpp"
#include "Bullet.hpp"

class GameplayModule :
	public Module
{
public:
	GameplayModule();
	void Update() override;
	void Draw(std::shared_ptr<sf::RenderWindow> window) override;
	void EventHandler(sf::Event& event, std::shared_ptr<sf::RenderWindow> window) override;
private:
	const float speed = 200.f;
	const sf::Time shootCooldown = sf::seconds(0.1f);
	const sf::Time gcCooldown = sf::seconds(5.f);

	bool moveRight;
	bool moveLeft;
	bool moveDown;
	bool moveUp;

	bool shoot;

	bool movingDiagonally();

	sf::RectangleShape player;
	std::vector<Bullet> bullets;

	sf::Clock deltaTimeClock;
	sf::Clock shootCooldownTimer;
	sf::Clock gcTimer;

	sf::RectangleShape globalBound;
};

