#pragma once
#include <memory>

using namespace std;

class AudioManager
{
private:
	bool ismute;
	bool loaded;
	static shared_ptr<AudioManager> audioManager;
public:
	//! A constructor
	/*!
	constructor with argument
	*/
	AudioManager(bool);	

	//! A constructor
	/*!
	constructor by default
	*/
	AudioManager();

	//! A normal function without arguments and return nothing to pause the music
	void mute();	

	//! A normal function without arguments and return a bool value to play the music
	/*!
	\ return if the file is opened successfully and played
	*/
	bool play();									

	//! A function to get the AudioManager
	static shared_ptr<AudioManager> getAudioManager();

	//! A normal function without arguments and return a bool value mesure if it is mute
	/*!
	\ return if it is mute
	*/
	bool isMute();									
	 
};