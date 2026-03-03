#include "Screen.hpp"
#include "ScreenManagerRemoteControl.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>


void Screen::initialise() {}

void Screen::add_panel(std::unique_ptr<UIPanel> ui_panel,
    ScreenManagerRemoteControl* smrc, std::shared_ptr<InputHandler> i_handler)
{
    i_handler->initialise_input_handler(smrc, ui_panel->get_buttons(),
        &ui_panel->view, this);

    ui_panels.push_back(std::move(ui_panel));
    input_handlers.push_back(i_handler);
}

void Screen::handle_input(sf::RenderWindow& window) {

    auto end = input_handlers.end();
    while (window.pollEvent().has_value()) {
        sf::Event event = window.pollEvent();

        for (auto it = input_handlers.begin(); it != end; ++it) {
            (*it)->handle_input(window, event);
        }
    }
}

void Screen::update(float fps) {};

void Screen::draw(sf::RenderWindow& window) {
    for (auto it = ui_panels.begin(); it != ui_panels.end(); ++it) {
        (*it)->draw(window);
    }
}
