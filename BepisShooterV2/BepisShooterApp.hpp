#pragma once

#include "App.hpp"
#include "MainMenuModule.hpp"

#include <SFML/Graphics.hpp>

class BepisShooterApp :
	public App
{
public:
	BepisShooterApp();
	void Run() override;
	void Init() override;
private:
	void mainLoop() override;
	sf::Clock mainClock;
	bool playing;
	std::shared_ptr<sf::RenderWindow> window;
	std::unique_ptr<Module> app;
};

