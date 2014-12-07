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
	AudioManager(bool);								//constructor
	AudioManager();									//constructor
	void mute();									//stop music
	bool play();									//play music

	static shared_ptr<AudioManager> getAudioManager();
	bool isMute();									//return the state of music
	 
};