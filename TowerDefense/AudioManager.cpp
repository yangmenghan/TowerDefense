#pragma once
#include "AudioManager.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>




sf::Music music;// Declare a new music


AudioManager::AudioManager()
{
	isMute = false;
};


AudioManager::AudioManager(bool b)
{
	isMute = b;
};

void AudioManager::mute()
{
	music.stop(); //Stop it
};

bool AudioManager::play()
{
	if (!music.openFromFile("music.ogg"))  // Open it from an audio file
		return 1; // Error
	music.play();  // Play it
	music.setLoop(true); // Make it loop
};

AudioManager* AudioManager::getAudioManager()
{
	if (NULL == audioManager)
	{
		audioManager = new AudioManager;
	}
	return &audioManager;
};

//test

void main()
{
	music.play();

}