#pragma once
#ifndef BITMAP_STORE_H
#define BITMAP_STORE_H

#include <SFML/Graphics.hpp>
#include <map>


class BitmapStore {

private:

    std::map<std::string, sf::Texture> bitmaps;
    static BitmapStore *single_instance;

public:

    BitmapStore();
    static sf::Texture& get_bitmap(std::string const& name);
    static void add_bitmap(std::string const& name);
};

#endif
