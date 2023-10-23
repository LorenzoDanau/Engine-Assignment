#include "AssetManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

std::map<std::string, sf::Texture> AssetManager::Textures;
std::map<std::string, sf::SoundBuffer> AssetManager::SoundBuffers;
std::map<std::string, std::shared_ptr<sf::Music>> AssetManager::Musics;
std::map<std::string, sf::Font> AssetManager::Fonts;

void AssetManager::LoadTexture(const std::string& name, const std::string& fileName) {
    sf::Texture texture;
    if (texture.loadFromFile(fileName)) {
        Textures[name] = texture;
    }
}

void AssetManager::LoadSoundBuffer(const std::string& name, const std::string& fileName) {
    sf::SoundBuffer soundBuffer;
    if (soundBuffer.loadFromFile(fileName)) {
        SoundBuffers[name] = soundBuffer;
    }
}

void AssetManager::LoadMusic(const std::string& name, const std::string& fileName) {
    std::shared_ptr<sf::Music> music = std::make_shared<sf::Music>();
    if (music->openFromFile(fileName)) {
        Musics[name] = music;
    }
}

void AssetManager::LoadFont(const std::string& name, const std::string& fileName) {
    sf::Font font;
    if (font.loadFromFile(fileName)) {
        Fonts[name] = font;
    }
}