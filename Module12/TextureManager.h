#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class TextureManager
{
    // static == one and only one of this thing
    static unordered_map<string, sf::Texture> _textures;
    static void LoadTexture(string textureName);

public:
    static sf::Texture& GetTexture(string textureName);
    static void Clear(); // Call this at the end of main();
};