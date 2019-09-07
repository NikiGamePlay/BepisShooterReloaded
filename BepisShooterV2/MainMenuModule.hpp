#pragma once
#include "Module.hpp"
#include "Button.hpp"

typedef sf::RectangleShape LaunchGameButton;
typedef sf::RectangleShape ExitGameButton;


class MainMenuModule :
	public Module
{
public:
	MainMenuModule();
	void Update() override;
	void Draw(std::shared_ptr<sf::RenderWindow> window) override;
	void EventHandler(sf::Event& event, std::shared_ptr<sf::RenderWindow> window) override;
private:
	sf::RectangleShape background;
	Button launchGameButton;
	Button exitGameButton;

	sf::Texture backgroundTxt;
};

