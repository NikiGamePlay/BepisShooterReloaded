#pragma once
#include "Module.hpp"
#include "Bullet.hpp"
#include "BulletStorage.hpp"

class GameplayModule :
	public Module
{
public:
	// Default constructor
	GameplayModule();
	// Update happens per each frame
	void Update() override;
	// Also updated once per frame, draws elements onto the screen
	void Draw(std::shared_ptr<sf::RenderWindow> window) override;
	// Handles events, such as mouse clicks, keystrokes etc.
	void EventHandler(sf::Event& event, std::shared_ptr<sf::RenderWindow> window) override;
private:
	// player's movement speed
	const float playerSpeed = 200.f;
	// bullet's movement speed
	const float bulletSpeed = 500.f;
	const sf::Time shootCooldown = sf::seconds(0.1f);

	// movement booleans, they control whether we should do
	// a move in a given frame.
	bool moveRight = false;
	bool moveLeft = false;
	bool moveDown = false;
	bool moveUp = false;

	// shoot boolean, controls whether the Z key is pressed
	// which controls whether the player should shoot or not.
	bool shoot = false;

	// Detects diagonal movement
	bool movingDiagonally();

	// Player drawable-transformable entity
	sf::RectangleShape player;
	
	// deltaTime timer
	sf::Clock deltaTimeClock;
	// shoot cooldown timer
	sf::Clock shootCooldownTimer;

	// Bullet Storage, stores all bullets, updates and draws them.
	BulletStorage bulletStorage;
};

