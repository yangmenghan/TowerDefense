#pragma once
#include <memory>
#include <map>
#include <string>
#include <SFML/Audio.hpp>

using namespace std;

class AudioManager
{
private:
	bool ismute;
	bool loaded;
	static shared_ptr<AudioManager> audioManager;
	sf::Sound sound;
	map<string, sf::SoundBuffer> buffers;

public:
	//! A constructor
	/*!
	Constructor with argument
	*/
	AudioManager(bool);	

	//! A constructor
	/*!
	Constructor by default
	*/
	AudioManager();

	//! A normal function without arguments and return nothing to pause the music
	void mute();	

	//! A normal function without arguments and return a bool value to play the music
	/*!
	\return If the file is opened successfully and played
	*/
	bool play();

	bool playSound(string add);

	//! A function to get the AudioManager
	static shared_ptr<AudioManager> getAudioManager();

	//! A normal function without arguments and return a bool value mesure if it is mute
	/*!
	\return If it is mute
	*/
	bool isMute();									
	 
};