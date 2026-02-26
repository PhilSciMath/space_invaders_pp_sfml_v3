#include <SFML/Audio.hpp>
#include <assert.h>
#include "SoundEngine.hpp"


SoundEngine *SoundEngine::single_instance = nullptr;

SoundEngine::SoundEngine() :
    shoot_bfr("sounds/shoot.ogg"),
    shoot_snd(shoot_bfr),
    player_explode_bfr("sounds/player_explodes.ogg"),
    player_explode_snd(player_explode_bfr),
    invader_explode_bfr("sounds/invader_explodes.ogg"),
    invader_explode_snd(invader_explode_bfr),
    click_bfr("sounds/click.ogg"),
    click_snd(click_bfr)
{
    assert(single_instance == nullptr);
    single_instance = this;
}

void SoundEngine::play_shoot() {
    single_instance->shoot_snd.play();
}

void SoundEngine::play_invader_explode() {
    single_instance->invader_explode_snd.play();
}

void SoundEngine::play_player_explode() {
    single_instance->player_explode_snd.play();
}

void SoundEngine::play_click() {
    single_instance->click_snd.play();
}
