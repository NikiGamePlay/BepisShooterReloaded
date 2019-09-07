#include "GameplayModule.hpp"
#include <iostream>

GameplayModule::GameplayModule() {
	player.setPosition(100.f, 100.f);
	player.setSize(sf::Vector2f(25.f, 25.f));
	player.setFillColor(sf::Color::Cyan);

	globalBound.setPosition(0.f, 0.f);
	globalBound.setSize(sf::Vector2f(800.f, 600.f));
}

void GameplayModule::Update() {
	float deltaTime = deltaTimeClock.restart().asSeconds();
	float speed_ = movingDiagonally() ? speed / sqrt(2) : speed;

	if (moveDown)
		player.move(0.f, speed_ * deltaTime);
	if (moveUp)
		player.move(0.f, -speed_ * deltaTime);
	if (moveRight)
		player.move(speed_ * deltaTime, 0.f);
	if (moveLeft)
		player.move(-speed_ * deltaTime, 0.f);

	if (shoot && shootCooldownTimer.getElapsedTime() > shootCooldown) {
		shootCooldownTimer.restart();
		bullets.push_back(Bullet(270, 500.f, player.getPosition().x, player.getPosition().y));
	}

	for (auto& bullet : bullets) {
		bullet.Update();
	}

	if (gcTimer.getElapsedTime() > gcCooldown) {
		auto vecCopy = bullets;
		bullets.clear();
		// Concurrent mark phase
		for (auto it = vecCopy.begin(); it != vecCopy.end(); ++it) {
			if (globalBound.getGlobalBounds().intersects(it->GetGlobalBounds())) {
				bullets.push_back(*it);
			}
		}
		std::cout << "[GC] Out of " << vecCopy.size() << " elements, " << vecCopy.size() - bullets.size() << " got deleted leaving " << bullets.size() << " elements.\n";
		gcTimer.restart();
	}

	
}

void GameplayModule::Draw(std::shared_ptr<sf::RenderWindow> window) {
	window->draw(player);
	for (auto& bullet : bullets) {
		bullet.Draw(window);
	}
}

void GameplayModule::EventHandler(sf::Event& event, std::shared_ptr<sf::RenderWindow> window) {
	switch (event.type) {
	case sf::Event::KeyPressed:
		switch (event.key.code) {
		case sf::Keyboard::Up:
			moveUp = true;
			break;
		case sf::Keyboard::Down:
			moveDown = true;
			break;
		case sf::Keyboard::Right:
			moveRight = true;
			break;
		case sf::Keyboard::Left:
			moveLeft = true;
			break;
		case sf::Keyboard::Z:
			shoot = true;
			break;
		}
		break;
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

bool GameplayModule::movingDiagonally() {
	return
		(
			(moveDown && moveRight) ||
			(moveDown && moveLeft) ||
			(moveUp && moveLeft) ||
			(moveUp && moveRight)
		);
}
