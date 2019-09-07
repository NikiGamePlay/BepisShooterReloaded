#include "MainMenuModule.hpp"
#include <iostream>

MainMenuModule::MainMenuModule() :
	launchGameButton("playgamebtn", 381.f, 100.f),
	exitGameButton("playgamebtn", 381.f, 100.f)
{
	launchGameButton.GetRectangle()->setPosition(100.f, 100.f);
	exitGameButton.GetRectangle()->setPosition(200.f, 200.f);
	sf::Image img;
	img.loadFromFile(".\\assets\\textures\\background.png");
	backgroundTxt.loadFromImage(img);
	backgroundTxt.setSmooth(true);
	background.setSize(sf::Vector2f(800.f, 600.f));
	background.setTexture(&backgroundTxt);
}

void MainMenuModule::Update() {

}

void MainMenuModule::Draw(std::shared_ptr<sf::RenderWindow> window) {
	background.setTexture(&backgroundTxt);
	window->draw(background);
	launchGameButton.Draw(window);
	exitGameButton.Draw(window);
}

void MainMenuModule::EventHandler(sf::Event& event, std::shared_ptr<sf::RenderWindow> window) {
	auto mousepos = sf::Mouse::getPosition(*window);
	auto mouseposMapped = window->mapPixelToCoords(mousepos);

	switch (event.type) {
	case sf::Event::MouseButtonPressed:
		if (launchGameButton.CheckIfClicked(mouseposMapped))
			MState = change_module;
		if (exitGameButton.CheckIfClicked(mouseposMapped))
			MState = ready_to_exit;
		break;
	}
}