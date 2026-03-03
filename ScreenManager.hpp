#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include "GameScreen.hpp"
#include "ScreenManagerRemoteControl.hpp"
#include "SelectScreen.hpp"
// #include "LevelManager.hpp"
#include "BitmapStore.hpp"
#include <iostream>


class ScreenManager : public ScreenManagerRemoteControl {

private:

    std::map <std::string, std::unique_ptr<Screen>> screens;
    // LevelManager level_manager;

protected:

    std::string current_screen = "Select";

public:

    BitmapStore bitmap; // A new version of TextureHolder from the other games

    ScreenManager(sf::Vector2i resolution);

    void update(float fps);
    void draw(sf::RenderWindow& window);
    void handle_input(sf::RenderWindow& window);

    /*
     * **********************************************************
     * From ScreenManagerRemoteControl interface
     * **********************************************************
     */
    void switch_screens(std::string screen_to_switch_to) override
    {
        current_screen = "" + screen_to_switch_to;
        screens[current_screen]->initialise();
    }

    void load_level_in_play_mode(std::string screen_to_load) override
    {
        //level_manager.get_game_objects().clear();
        //level_manager.load_game_objects_for_play_mode(screen_to_load);
        switch_screens("Game");
    }

    /*
    std::vector<GameObject>& ScreenManagerRemoteControl::get_game_objects() {
      return level_manager.get_game_objects();
    }

    GameObjectSharer& share_game_object_sharer() {
        return level_manager;
    }
    */
};
