#include "BepisShooterApp.hpp"
#include "MainMenuModule.hpp"
#include "GameplayModule.hpp"
#include <iostream>

BepisShooterApp::BepisShooterApp() {
	window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600, 32), "bepisshootergamev2 0.1.1");
	playing = true;
	app = nullptr;
}

void BepisShooterApp::Init() {
	window->setFramerateLimit(240);
	app = std::make_unique<MainMenuModule>();
}

void BepisShooterApp::Run() {
	mainClock.restart(); 
	while (playing && window->isOpen()) {
		if (app->MState == change_module) {
			app.reset(std::make_unique<GameplayModule>().release());
			continue;
		}
		
		mainLoop();
	}
}

void BepisShooterApp::mainLoop() {
	window->clear();
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			playing = false;
			window->close();
			exit(0);
			break;
		}
		app->EventHandler(event, window);
	}
	app->Update();
	app->Draw(window);
	window->display();
}
