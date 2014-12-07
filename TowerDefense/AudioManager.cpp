#pragma once
#include "AudioManager.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include <memory>
#include "Config.h"

using namespace std;


shared_ptr<AudioManager> AudioManager::audioManager = NULL;

sf::Music music;                                     // Declare a new music


AudioManager::AudioManager()
{
	ismute = false;
	loaded = false;
};


AudioManager::AudioManager(bool b)
{
	ismute = b;
};

void AudioManager::mute()
{
	if (music.Playing){
		music.pause();		//Pause it
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
		music.play();
		music.setLoop(true);							// Make it loop
	}
	return true;
	
};

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