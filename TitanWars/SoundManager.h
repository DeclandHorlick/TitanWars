#include <iostream>

#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp" 

#include "SFML\Audio.hpp"

#ifndef SOUNDMANAGER
#define SOUNDMANAGER

class SoundManager
{


public:
	
	
	static SoundManager* GetInstance();
	void loadSounds();
	void carBounce();
	void carOww();
	void stopIt();
	void leaveUsAlone();
	void somebodySaveUs();
	void helpMe();
	void scream();
	void bombsAway();
	void puke();
	void puke2();
	void puke3();
	void howDareYou();
	void itsGodzilla();
	void endingMove();
	void ohMyGod();
	void eatThis();
	void niceShot();
	void winner();
	void bombBang();
	void whatsGoin();
	void haHa();
	void fart();
	void choose();
	void mainMusic();
	void selected();
	void levelSsound();
	void fight();
	void p1Sound();
	void p2Sound();

	~SoundManager()
	{
		instanceFlag = false;
	}
	

private:

	sf::SoundBuffer carBounceBuffer;
	sf::Sound carBounceMusic;

	sf::SoundBuffer carOwwBuffer;
	sf::Sound carOwwMusic;

	sf::SoundBuffer stopItBuffer;
	sf::Sound stopItMusic;

	sf::SoundBuffer leaveUsAloneBuffer;
	sf::Sound leaveUsAloneMusic;

	sf::SoundBuffer somebodySaveUsBuffer;
	sf::Sound somebodySaveUsMusic;

	sf::SoundBuffer helpMeBuffer;
	sf::Sound helpMeMusic;

	sf::SoundBuffer screamBuffer;
	sf::Sound screamMusic;

	sf::SoundBuffer bombsAwayBuffer;
	sf::Sound bombsAwayMusic;

	sf::SoundBuffer pukeBuffer;
	sf::Sound pukeMusic;

	sf::SoundBuffer puke1Buffer;
	sf::Sound puke1Music;
	
	sf::SoundBuffer puke2Buffer;
	sf::Sound puke2Music;

	sf::SoundBuffer howDareYouBuffer;
	sf::Sound howDareYouMusic;

	sf::SoundBuffer itsGodzillaBuffer;
	sf::Sound itsGodzillaMusic;

	sf::SoundBuffer endingMoveBuffer;
	sf::Sound endingMoveMusic;

	sf::SoundBuffer ohMyGodBuffer;
	sf::Sound ohMyGodMusic;

	sf::SoundBuffer eatThisBuffer;
	sf::Sound eatThisMusic;

	sf::SoundBuffer niceShotBuffer;
	sf::Sound niceShotMusic;

	sf::SoundBuffer winnerBuffer;
	sf::Sound winnerMusic;

	sf::SoundBuffer bombBangBuffer;
	sf::Sound bombBangMusic;

	sf::SoundBuffer hahaBuffer;
	sf::Sound hahaMusic;

	sf::SoundBuffer whatsgoinBuffer;
	sf::Sound whatsgoinMusic;

	sf::SoundBuffer fartBuffer;
	sf::Sound fartMusic;

	sf::SoundBuffer switchBuffer;
	sf::Sound switchMusic;

	sf::SoundBuffer selectedBuffer;
	sf::Sound selectedMusic;

	sf::SoundBuffer mainMusicBuffer;
	sf::Music mainMMusic;

	sf::SoundBuffer levelSsoundBuffer;
	sf::Sound levelSsoundMusic;

	sf::SoundBuffer p2Buffer;
	sf::Sound p2Music;

	sf::SoundBuffer p1Buffer;
	sf::Sound p1Music;

	sf::SoundBuffer fightsoundBuffer;
	sf::Sound fightMusic;

	SoundManager()
	{

	}

	static bool instanceFlag;
	static SoundManager* instance;
};
#endif

