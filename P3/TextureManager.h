#pragma once
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
using std::map;
using std::string;

class TextureManager
{
	map<string, sf::Texture> _stringTextureMap;
public:
	bool loadTexture(string name, string filepath);
	const sf::Texture& getTexture(string name) const;
};

