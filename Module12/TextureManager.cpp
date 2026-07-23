#include "TextureManager.h"

// Redeclare static variable so it can be used elsewhere in our code
unordered_map<string, sf::Texture> TextureManager::_textures;

void TextureManager::LoadTexture(string textureName)
{
	string path = "images/";
	path += textureName + ".png";
	_textures[textureName].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName)
{
	// Check to see if the texture already exists (i.e. has it been loaded yet?)
	if (_textures.find(textureName) == _textures.end())
		LoadTexture(textureName);

	return _textures[textureName];
}

void TextureManager::Clear()
{
	_textures.clear();
}