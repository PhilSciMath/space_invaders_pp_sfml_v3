#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ScreenManager.hpp"
#include "SoundEngine.hpp"


class GameEngine {

private:

    sf::Clock clock;
    sf::Time dt;
    sf::RenderWindow window;
    sf::Vector2f resolution;
    sf::Vector2u mode;
    float fps = 0;

    std::unique_ptr<ScreenManager> screen_manager;

    void handle_input();
    void update();
    void draw();

public:

    GameEngine();
    SoundEngine sound_engine;
    void run();
};
