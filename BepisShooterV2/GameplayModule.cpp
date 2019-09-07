#include "GameplayModule.hpp"
#include <iostream>

GameplayModule::GameplayModule() {
	// initalize player
	player.setPosition(100.f, 100.f);
	player.setSize(sf::Vector2f(25.f, 25.f));
	player.setFillColor(sf::Color::Cyan);
}

void GameplayModule::Update() {
	// Get deltaTime
	float deltaTime = deltaTimeClock.restart().asSeconds();
	// Calculate speed (whether moving diagonally)
	float speed_ = movingDiagonally() ? playerSpeed / sqrt(2) : playerSpeed;

	// movement handler
	if (moveDown)
		player.move(0.f, speed_ * deltaTime);
	if (moveUp)
		player.move(0.f, -speed_ * deltaTime);
	if (moveRight)
		player.move(speed_ * deltaTime, 0.f);
	if (moveLeft)
		player.move(-speed_ * deltaTime, 0.f);

	// check whether the Z key has been pressed and if there is no cooldown
	if (shoot && shootCooldownTimer.getElapsedTime() > shootCooldown) {
		// restart the cooldown timer
		shootCooldownTimer.restart();
		// fire a bullet (by adding it to the bullet storage)
		bulletStorage.CreateBullet(270, 500.f, player.getPosition().x, player.getPosition().y);
	}
	// update bullets
	bulletStorage.Update();	
}

void GameplayModule::Draw(std::shared_ptr<sf::RenderWindow> window) {
	// draw player entity
	window->draw(player);
	// draw bullets
	bulletStorage.DrawBullets(window);
}

void GameplayModule::EventHandler(sf::Event& event, std::shared_ptr<sf::RenderWindow> window) {
	// switch (event type)
	switch (event.type) {
		// Key pressed event
	case sf::Event::KeyPressed:
		// switch (pressed key's code)
		switch (event.key.code) {
			// Up arrow pressed (movement)
		case sf::Keyboard::Up:
			moveUp = true;
			break;
			// Down arrow pressed (movement)
		case sf::Keyboard::Down:
			moveDown = true;
			break;
			// Right arrow pressed (movement)
		case sf::Keyboard::Right:
			moveRight = true;
			break;
			// Left arrow pressed (movement)
		case sf::Keyboard::Left:
			moveLeft = true;
			break;
			// Z key pressed (shoot)
		case sf::Keyboard::Z:
			shoot = true;
			break;
		}
		break;
		// Key released event
	case sf::Event::KeyReleased:
		switch (event.key.code) {
		case sf::Keyboard::Up:
			moveUp = false;
			break;
		case sf::Keyboard::Down:
			moveDown = false;
			break;
		case sf::Keyboard::Right:
			moveRight = false;
			break;
		case sf::Keyboard::Left:
			moveLeft = false;
			break;
		case sf::Keyboard::Z:
			shoot = false;
			break;
		}
		break;
	}
}

// Detect diagonal movement by checking each possibility
bool GameplayModule::movingDiagonally() {
	return
		(
			(moveDown && moveRight) || // south-east movement
			(moveDown && moveLeft) || // south-west movement
			(moveUp && moveLeft) || // north-west movement
			(moveUp && moveRight) // north-east movement
		);
}
