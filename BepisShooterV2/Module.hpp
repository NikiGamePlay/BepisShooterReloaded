#pragma once
#include <SFML/Graphics.hpp>
#include <memory>


/// ModuleState controls whether the module should be unloaded or still work.
enum ModuleState {
	working,
	ready_to_exit,
	change_module
};

class Module {
public:
	ModuleState MState = working;
	float DeltaTime = 0.f;
	virtual void Update() = 0;
	virtual void Draw(std::shared_ptr<sf::RenderWindow> window) = 0;
	virtual void EventHandler(sf::Event& event, std::shared_ptr<sf::RenderWindow> window) = 0;
};
