#pragma once
#include "Bullet.hpp"

class BulletStorage
{
public:
	// Default constructor
	BulletStorage();
	// Constructor that defines the GC cooldown.
	BulletStorage(float gccooldown);
	// Create a bullet, given it's angle, speed, x (coordinate) and y (coordinate).
	void CreateBullet(float angle, float speed, float x, float y);
	// Updates bullets (movement) and runs the GC if needed.
	void Update();
	// Draws bullets onto the screen
	void DrawBullets(std::shared_ptr<sf::RenderWindow> window);
private:
	// runs GC
	void runGC();
	// GC interval
	const sf::Time gcCooldown;
	// bullet array
	std::vector<Bullet> bullets;
	// GC timer
	sf::Clock gcTimer;
	// bounds of the screen/map, used by the GC to determine whether
	// the bullet should be deleted or not.
	sf::RectangleShape globalBound;
};

