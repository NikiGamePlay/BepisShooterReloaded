#include "Bullet.hpp"
#define PI 3.14f

Bullet::Bullet(float angle, float speed, float startx, float starty) : speed(speed) {
	// Movement offset
	float rad = angle * (PI / 180.f);
	offsetx = std::cos(rad);
	offsety = std::sin(rad);
	// Bullet size, outline and colour
	bulletEntity.setRadius(5.f);
	bulletEntity.setFillColor(sf::Color::Red);
	bulletEntity.setOutlineThickness(5.f);
	bulletEntity.setOutlineColor(sf::Color::Black);
	bulletEntity.setPosition(sf::Vector2f(startx, starty));
}

void Bullet::Draw(std::shared_ptr<sf::RenderWindow> window) {
	window->draw(bulletEntity);
}

void Bullet::Update() {
	float deltaTime = deltaTimeClock.restart().asSeconds();
	bulletEntity.move(offsetx * speed * deltaTime, offsety * speed * deltaTime);
}

sf::Vector2f Bullet::GetPosition() {
	return bulletEntity.getPosition();
}

sf::FloatRect Bullet::GetGlobalBounds() {
	return bulletEntity.getGlobalBounds();
}