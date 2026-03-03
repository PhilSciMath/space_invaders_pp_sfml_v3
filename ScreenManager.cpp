#include "ScreenManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


ScreenManager::ScreenManager(sf::Vector2i resolution) {

    screens["Game"] = std::make_unique<GameScreen>(
        this, resolution);
    screens["Select"] = std::make_unique<GameScreen>(
        this, resolution);
}

void ScreenManager::handle_input(sf::RenderWindow& window) {
    screens[current_screen]->handle_input(window);
}

void ScreenManager::update(float fps) {
    screens[current_screen]->update(fps);
}

void ScreenManager::draw(sf::RenderWindow& window) {
    screens[current_screen]->draw(window);
}
