#pragma once
#include "AudioManager.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <memory>
#include "Config.h"

using namespace std;


shared_ptr<AudioManager> AudioManager::audioManager = NULL;

/*! 
Declare a new music
*/
sf::Music music;                                    

AudioManager::AudioManager()
{
	ismute = false;
	loaded = false;
	
	buffers.emplace(SOUND_DAMAGE, sf::SoundBuffer());
	buffers.at(SOUND_DAMAGE).loadFromFile(SOUND_DAMAGE);

	buffers.emplace(SOUND_EXPLOSION, sf::SoundBuffer());
	buffers.at(SOUND_EXPLOSION).loadFromFile(SOUND_EXPLOSION);

	buffers.emplace(SOUND_MONEY, sf::SoundBuffer());
	buffers.at(SOUND_MONEY).loadFromFile(SOUND_MONEY);

	buffers.emplace(SOUND_NORMAL_ATTACK, sf::SoundBuffer());
	buffers.at(SOUND_NORMAL_ATTACK).loadFromFile(SOUND_NORMAL_ATTACK);

	buffers.emplace(SOUND_SLOW_ATTACK, sf::SoundBuffer());
	buffers.at(SOUND_SLOW_ATTACK).loadFromFile(SOUND_SLOW_ATTACK);

	buffers.emplace(SOUND_ZONE_ATTACK, sf::SoundBuffer());
	buffers.at(SOUND_ZONE_ATTACK).loadFromFile(SOUND_ZONE_ATTACK);

	buffers.emplace(SOUND_GAMEOVER, sf::SoundBuffer());
	buffers.at(SOUND_GAMEOVER).loadFromFile(SOUND_GAMEOVER);

	buffers.emplace(SOUND_WIN, sf::SoundBuffer());
	buffers.at(SOUND_WIN).loadFromFile(SOUND_WIN);

	buffers.emplace(SOUND_SELECT, sf::SoundBuffer());
	buffers.at(SOUND_SELECT).loadFromFile(SOUND_SELECT);

	buffers.emplace(SOUND_HOVER, sf::SoundBuffer());
	buffers.at(SOUND_HOVER).loadFromFile(SOUND_HOVER);
};

AudioManager::AudioManager(bool b)
{
	ismute = b;
};

void AudioManager::mute()
{
	if (music.Playing){
		music.pause();
		ismute = true;
	}
									
};

bool AudioManager::play()
{
	if (loaded){
		if (music.Paused){
			music.play();
			ismute = false;
		}
	}
	else {
		if (!music.openFromFile(MAIN_BGM))
		{
			return false;
		}
		loaded = true;
		ismute = false;
		music.setVolume(0);
		music.play();
		music.setLoop(true);							// Make it loop
	}
	return true;
	
};

bool  AudioManager::playSound(string add) {

	if (!ismute){
		sound.setBuffer(buffers.at(add));
		sound.play();
		return true;
	}
	return false;
}

shared_ptr<AudioManager> AudioManager::getAudioManager()
{
	if (NULL == audioManager)
	{
		audioManager = make_shared<AudioManager>();
	}
	return audioManager;
};

bool AudioManager::isMute()
{
	return ismute;
};