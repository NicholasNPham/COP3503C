#pragma once
#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include <unordered_map>
#include <string>

=======
#include <string>
#include <unordered_map>
>>>>>>> 52bc70f1e0efb2e454090e0c3875177993cb2448
using std::string;
using std::unordered_map;

class TextureManager
{
<<<<<<< HEAD
	// static == one and only one of this thing
	static unordered_map<string, sf::Texture> _textures;
	static void LoadTexture(string textureName);
	
public:
	static sf::Texture& GetTexture(string textureName);
	static void Clear(); // Call this at the end of main 
=======
    // static == one and only one of this thing
    static unordered_map<string, sf::Texture> _textures;
    static void LoadTexture(string textureName);

public:
    static sf::Texture& GetTexture(string textureName);
    static void Clear(); // Call this at the end of main();
>>>>>>> 52bc70f1e0efb2e454090e0c3875177993cb2448
};