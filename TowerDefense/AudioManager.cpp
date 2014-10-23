#pragma once
#include "AudioManager.h"
#include <SFML/Audio.hpp>
#include <Music.hpp>




sf::Music music;// Declare a new music
enum  Status 
{
	Stopped,
	Paused,
	Playing
}
//Enumeration of the sound source states

void AudioManager::mute()
{
	music.stop();  //Stop it
};

bool AudioManager::play()
{
	if (!music.openFromFile("music.ogg"))  // Open it from an audio file
		return 1; // Error
	music.play();  // Play it
	music.setLoop(true); // Make it loop
};

void AudioManager::getAudioManager()
{
	Status music.getStatus() const; //Get the current status of the stream(stopped, paused, playing)
};
