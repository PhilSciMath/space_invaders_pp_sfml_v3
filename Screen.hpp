#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "InputHandler.hpp"
#include "UIPanel.hpp"
#include "ScreenManagerRemoteControl.hpp"


class InputHandler;

class Screen {
private:
    std::vector<std::shared_ptr<InputHandler>> input_handlers;
    std::vector<std::unique_ptr<UIPanel>> ui_panels;

protected:
    void add_panel(std::unique_ptr<UIPanel> panel,
                   ScreenManagerRemoteControl* smrc,
                   std::shared_ptr<InputHandler> ihandler);

public:
    virtual void initialise();
    void virtual update(float fps);
    void virtual draw(sf::RenderWindow& window);
    void handle_input(sf::RenderWindow& windwo);

    sf::View view;
};
