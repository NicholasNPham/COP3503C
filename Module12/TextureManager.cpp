#include "TextureManager.h"

// Redeclare static variable so it can be used elsewhere in our code
unordered_map<string, sf::Texture> TextureManager::_textures;

void TextureManager::LoadTexture(string textureName)
{
<<<<<<< HEAD
	string path = "image/";
=======
	string path = "images/";
>>>>>>> 52bc70f1e0efb2e454090e0c3875177993cb2448
	path += textureName + ".png";
	_textures[textureName].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName)
{
<<<<<<< HEAD
	// check to see if the texture already exists (i.e. has it been loaded yet?)
=======
	// Check to see if the texture already exists (i.e. has it been loaded yet?)
>>>>>>> 52bc70f1e0efb2e454090e0c3875177993cb2448
	if (_textures.find(textureName) == _textures.end())
		LoadTexture(textureName);

	return _textures[textureName];
}

void TextureManager::Clear()
{
	_textures.clear();
}