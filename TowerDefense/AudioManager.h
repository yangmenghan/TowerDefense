#pragma once


class AudioManager
{
private:
	bool isMute;
	static AudioManager* audioManager;
public:
	AudioManager(bool);
	AudioManager();
	void mute();
	bool play();
	AudioManager getAudioManager();
	 
};