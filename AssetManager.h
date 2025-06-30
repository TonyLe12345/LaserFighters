#pragma once


using namespace std;
using namespace sf;


class AssetManager
{

public:

    AssetManager( ) { }
    ~AssetManager( ) { }

    void LoadTexture( string name, string fileName );
    Texture &GetTexture( string name );

    void LoadFont (string name, string fileName );
    Font &GetFont( string name );

    //void LoadTextureHeap( string name, string fileName );
    //Texture &GetTextureHeap( string name );



private:
    map<string, Texture> _textures;
    map<string, Font> _fonts;
    //Texture *_spriteTexture;
};

