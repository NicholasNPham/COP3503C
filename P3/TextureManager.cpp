#include "TextureManager.h"
using namespace std;

bool TextureManager::loadTexture(string name, string filepath)
{
	sf::Texture texture;
	bool success = texture.loadFromFile(filepath);

	if (success)
	{
	_stringTextureMap[name] = texture;
	}

	return success;
}

const sf::Texture& TextureManager::getTexture(string name) const {
	return _stringTextureMap.at(name);
}