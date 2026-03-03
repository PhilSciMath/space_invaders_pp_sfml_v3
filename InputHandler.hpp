#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <vector>
#include "Button.hpp"
#include "Screen.hpp"
#include "ScreenManagerRemoteControl.hpp"


class Screen;

class InputHandler {
    private:
        Screen* parent_screen;
        std::vector<std::shared_ptr<Button>> buttons;
        sf::View* pointer_to_ui_panel_view;
        ScreenManagerRemoteControl* sm_remote_control;

    public:
        void initialise_input_handler(
            ScreenManagerRemoteControl* smrc,
            std::vector<std::shared_ptr<Button>> bs,
            sf::View* pointer_to_ui_view,
            Screen* p_screen);

        void handle_input(sf::RenderWindow& window, sf::Event& event);

        virtual void handle_gamepad();
        virtual void handle_key_pressed(sf::Event& event,
            sf::RenderWindow& window);
        virtual void handle_key_released(sf::Event& event,
            sf::RenderWindow& window);
        virtual void handle_left_click(std::string& button_interacted_with,
            sf::RenderWindow& window);

        sf::View* get_pointer_to_ui_view();

        ScreenManagerRemoteControl*
            get_pointer_to_screen_manager_remote_control();

        Screen* get_parent_screen();
};
