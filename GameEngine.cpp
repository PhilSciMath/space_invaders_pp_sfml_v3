#include "GameEngine.hpp"
#include <SFML/Window/VideoMode.hpp>


GameEngine::GameEngine() {

    // Creating a game window
    mode = sf::VideoMode::getDesktopMode().size;
    resolution = static_cast<sf::Vector2f>(mode);

    window.create(sf::VideoMode(mode), "Space Invaders ++",
                  sf::State::Fullscreen);

    screen_manager = std::make_unique<ScreenManager>(resolution);

}

void GameEngine::run() {

    while(window.isOpen()) {

        dt = clock.restart();
        fps = dt.asSeconds();

        handle_input();
        update();
        draw();
    }
}

// Input handling responsibility is now delegated to the screen_manager
void GameEngine::handle_input() {
    screen_manager->handle_input(window);
}

// Update responsibility is now delegated to the screen_manager
void GameEngine::update() {
    screen_manager->update(fps);
}

// This function will still clear and display content but drawing is now
// done by the screen_manager
void GameEngine::draw() {

    window.clear(sf::Color::Black);
    screen_manager->draw(window);
    window.display();
}
