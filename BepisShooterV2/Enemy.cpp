#include "Enemy.hpp"

Enemy::Enemy() : maxHP(1000.f) {
	HP = maxHP;
}

Enemy::Enemy(float maxHP) : maxHP(maxHP) {
	HP = maxHP;
}

void Enemy::Update() {

}

void Enemy::Draw(std::shared_ptr<sf::RenderWindow> window) {

}

void Enemy::Hit(float damage) {
	HP -= damage;
	if (HP <= 0.f) {
		this->EntityState = EntityState::Dead;
	}
}

sf::FloatRect Enemy::GetHitbox() {
	return enemyEntity.getGlobalBounds();
}
