#pragma once


class AudioManager
{
private:
	bool ismute;
	static AudioManager* audioManager;
public:
	AudioManager(bool);								//constructor
	AudioManager();									//constructor
	void mute();									//stop music
	bool play();									//play music

	static AudioManager getAudioManager();
	bool isMute();									//return the state of music
	 
};