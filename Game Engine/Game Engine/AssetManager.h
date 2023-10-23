#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <string>
#include <map>
#include <memory>

// no singleton implementation needed for this class
class AssetManager {
public:
    static std::map<std::string, sf::Texture> Textures;
    static std::map<std::string, sf::SoundBuffer> SoundBuffers;
    static std::map<std::string, std::shared_ptr<sf::Music>> Musics;
    static std::map<std::string, sf::Font> Fonts;

    static void LoadTexture(const std::string& name, const std::string& fileName);
    static void LoadSoundBuffer(const std::string& name, const std::string& fileName);
    static void LoadMusic(const std::string& name, const std::string& fileName);
    static void LoadFont(const std::string& name, const std::string& fileName);
};