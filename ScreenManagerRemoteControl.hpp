// This is just an interface

#pragma once
#include <string>
#include <vector>
//#include "GameObject.hpp"
//#include "GameObjectSharer.hpp"

class ScreenManagerRemoteControl {

public:

    virtual void switch_screens(std::string screen_to_switch_to) = 0;
    virtual void load_level_in_play_mode(std::string screen_to_load) = 0;
    //virtual std::vector<GameObject>& get_game_objects() = 0;
    //virtual GameObjectSharer& share_game_object_sharer() = 0;
};
