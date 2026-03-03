#include "BitmapStore.hpp"
#include <assert.h>
#include <iostream>


BitmapStore *BitmapStore::single_instance = nullptr;

BitmapStore::BitmapStore() {

    assert(single_instance == nullptr);
    single_instance = this;
}

void BitmapStore::add_bitmap(std::string const& name) {

    // Get a reference to textures using single_instance
    auto& bitmaps = single_instance->bitmaps;

    // Create iterator, search for the required key-value pair using name
    auto key_val_pair = bitmaps.find(name);

    // If no match is found, save this one as new key-value pair
    if (key_val_pair == bitmaps.end()) {

        // Create new one
        auto &texture = bitmaps[name];

        // Load the texture in the usual way
        if (!texture.loadFromFile(name)) {
            std::cerr << "Failed loading the texture: \"" << name << "\".\n";
        }
    }
}

sf::Texture& BitmapStore::get_bitmap(std::string const& name) {

    // Get a reference to textures using single_instance
    auto& bmap = single_instance->bitmaps;

    // Create iterator, search for kvp using name
    auto key_val_pair = bmap.find(name);

    // Match found?
    if (key_val_pair != bmap.end()) {
        return key_val_pair->second;
    }
    else {

#ifdef debuggingOnConsole
        std::cout <<
            "BitmapStore::get_bitmap() Texture not found!" << std::endl;
#endif
        return key_val_pair->second;
    }
}
