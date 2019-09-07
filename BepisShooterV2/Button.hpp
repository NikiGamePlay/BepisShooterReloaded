#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
	Button(std::string txtName, float sizex, float sizey) {
		button.setSize(sf::Vector2f(sizex, sizey));
		if (!img.loadFromFile(".\\assets\\textures\\" + txtName + ".png"))
			exit(0x1);
		txt.loadFromImage(img);
		txt.setSmooth(true);
		button.setTexture(&txt, true);
	}
	bool CheckIfClicked(sf::Vector2f mpos) {
		return button.getGlobalBounds().contains(mpos);
	}
	void Draw(std::shared_ptr<sf::RenderWindow> window) {
		//txt.loadFromImage(img);
		button.setTexture(&txt);
		window->draw(button);
	}
	sf::RectangleShape* GetRectangle() {
		return &button;
	}
private:
	sf::Image img;
	sf::Texture txt;
	sf::RectangleShape button;
};
