#pragma once
#include "AudioManager.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>




sf::Music music;                                     // Declare a new music


AudioManager::AudioManager()
{
	ismute = false;
};


AudioManager::AudioManager(bool b)
{
	ismute = b;
};

void AudioManager::mute()
{
	music.stop();									 //Stop it
};

bool AudioManager::play()
{
	if (!music.openFromFile("test.mp3"))			// Open it from an audio file
		return 1;									// Error
	music.play();									// Play it
	music.setLoop(true);							// Make it loop
};

AudioManager AudioManager::getAudioManager()
{
	if (NULL == audioManager)
	{
		audioManager = new AudioManager;
	}
	return *audioManager;
};

bool AudioManager::isMute()
{
	return ismute;
};