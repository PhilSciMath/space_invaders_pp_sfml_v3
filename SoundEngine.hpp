#pragma once
#include <SFML/Audio/SoundBuffer.hpp>
#ifndef SOUND_ENGINE_HPP
#define SOUND_ENGINE_HPP

#include <SFML/Audio.hpp>


class SoundEngine {

private:

    sf::SoundBuffer shoot_bfr;
    sf::SoundBuffer player_explode_bfr;
    sf::SoundBuffer invader_explode_bfr;
    sf::SoundBuffer click_bfr;

    sf::Sound shoot_snd;
    sf::Sound player_explode_snd;
    sf::Sound invader_explode_snd;
    sf::Sound click_snd;
    //sf::Sound oh_snd;
    //sf::Sound uh_snd;

public:

    SoundEngine();

    static void play_shoot();
    static void play_player_explode();
    static void play_invader_explode();
    static void play_click();

    static SoundEngine *single_instance;
};

#endif
