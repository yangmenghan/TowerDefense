#pragma once


class AudioManager
{
private:
	bool ismute;
	static AudioManager* audioManager;
public:
	AudioManager(bool);
	AudioManager();
	void mute();
	bool play();

	static AudioManager getAudioManager();
	bool isMute();
	 
};