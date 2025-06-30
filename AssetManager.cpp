#include <map>
#include <SFML/Graphics.hpp>
#include"AssetManager.h"

using namespace std;
using namespace sf;

//The AssetManager handles loading and getting art assets
//eg. so that each time the program draws a ship jpg it's not loading it from a file each time



// loads a texture for the game to implement
void AssetManager::LoadTexture( string name, string fileName )
{
    Texture tex;
    if (tex.loadFromFile(fileName))
    {
        this->_textures[name] = tex;
    }
}

// uses a previously loaded texture
Texture &AssetManager::GetTexture ( string name )
{
    return this->_textures.at( name );
}


// loads a font for the game to implement
void AssetManager::LoadFont( string name, string fileName )
{
    Font font;
    if (font.loadFromFile(fileName))
    {
        this->_fonts[name] = font;
    }
}


// uses a previously loaded font
Font &AssetManager::GetFont ( string name )
{
    return this->_fonts.at( name );
}