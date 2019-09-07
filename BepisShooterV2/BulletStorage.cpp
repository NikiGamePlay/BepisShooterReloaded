#include "BulletStorage.hpp"

BulletStorage::BulletStorage() : gcCooldown(sf::seconds(5.f)) {
	globalBound.setPosition(0.f, 0.f);
	globalBound.setSize(sf::Vector2f(800, 600));
}

BulletStorage::BulletStorage(float gccooldown) : gcCooldown(sf::seconds(gccooldown)) {
	globalBound.setPosition(0.f, 0.f);
	globalBound.setSize(sf::Vector2f(800, 600));
}

void BulletStorage::CreateBullet(float angle, float speed, float x, float y) {
	bullets.push_back(Bullet(angle, speed, x, y));
}

void BulletStorage::Update() {
	for (auto& bullet : bullets) {
		bullet.Update();
	}
	if (gcTimer.getElapsedTime() > gcCooldown) {
		runGC();
	}
}

void BulletStorage::runGC() {
	auto vecCopy = bullets;
	bullets.clear();
	for (auto it = vecCopy.begin(); it != vecCopy.end(); ++it) {
		if (globalBound.getGlobalBounds().intersects(it->GetGlobalBounds())) {
			bullets.push_back(*it);
		}
	}
	gcTimer.restart();
}

void BulletStorage::DrawBullets(std::shared_ptr<sf::RenderWindow> window) {
	for (auto& bullet : bullets)
		bullet.Draw(window);
}