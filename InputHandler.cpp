#include "InputHandler.hpp"
#include "ScreenManagerRemoteControl.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <sstream>


void InputHandler::initialise_input_handler(
    ScreenManagerRemoteControl* smrc,
    std::vector<std::shared_ptr<Button>> bs,
    sf::View* pointer_to_ui_view,
    Screen* p_screen)
{
        sm_remote_control = smrc;
        buttons = bs;
        pointer_to_ui_panel_view = pointer_to_ui_view;
        parent_screen = p_screen;
}

void InputHandler::handle_input(sf::RenderWindow& window,
    sf::Event& event)
{
    // Handle any key presses
    if (event.is<sf::Event::KeyPressed>())
        handle_key_pressed(event, window);
    if (event.is<sf::Event::KeyReleased>())
        handle_key_released(event, window);

    // Handle any left mouse click released
    if (event.is<sf::Event::MouseButtonReleased>()) {

        // Check every button in the vector buttons
        for (auto i = buttons.begin(); i < buttons.end(); ++i) {

            if ((*i)->collider.contains(
                window.mapPixelToCoords(sf::Mouse::getPosition(),
                       (*get_pointer_to_ui_view()))))
                {
                    // Capture the text of the button the was interacted with
                    // and pass it to the specialised version of this class
                    // if implemented
                    handle_left_click((*i)->text, window );
                    break;
                }
        }
    }

    handle_gamepad();
}

sf::View* InputHandler::get_pointer_to_ui_view() {
    return pointer_to_ui_panel_view;
}

ScreenManagerRemoteControl*
InputHandler::get_pointer_to_screen_manager_remote_control() {
    return sm_remote_control;
}

Screen* InputHandler::get_parent_screen() {
    return parent_screen;
}

// These functions do nothing unless handled by a derived class
void InputHandler::handle_gamepad() {}

void InputHandler::handle_key_pressed(sf::Event& event, sf::RenderWindow&
    window) {}

void InputHandler::handle_key_released(sf::Event& event,
    sf::RenderWindow& window) {}

void InputHandler::handle_left_click(std::string& button_interacted_with,
    sf::RenderWindow& window) {}
