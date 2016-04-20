#include "stdafx.h"
#include "SoundManager.h"



bool SoundManager::instanceFlag = false;
SoundManager* SoundManager::instance = NULL;



SoundManager* SoundManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new SoundManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}
void SoundManager::loadSounds()
{
	carBounceBuffer.loadFromFile("Sounds/Bounce.wav");
	carBounceMusic.setBuffer(carBounceBuffer);

	carOwwBuffer.loadFromFile("Sounds/Oww.wav");
	carOwwMusic.setBuffer(carOwwBuffer);

	stopItBuffer.loadFromFile("Sounds/StopIt.wav");
	stopItMusic.setBuffer(stopItBuffer);

	leaveUsAloneBuffer.loadFromFile("Sounds/Leaveus.wav");
	leaveUsAloneMusic.setBuffer(leaveUsAloneBuffer);

	somebodySaveUsBuffer.loadFromFile("Sounds/Somebodysave.wav");
	somebodySaveUsMusic.setBuffer(somebodySaveUsBuffer);

	helpMeBuffer.loadFromFile("Sounds/Helpme.wav");
	helpMeMusic.setBuffer(helpMeBuffer);

	screamBuffer.loadFromFile("Sounds/Ahhh.wav");
	screamMusic.setBuffer(screamBuffer);

	bombsAwayBuffer.loadFromFile("Sounds/Bombsaway.wav");
	bombsAwayMusic.setBuffer(bombsAwayBuffer);

	pukeBuffer.loadFromFile("Sounds/Puke.wav");
	pukeMusic.setBuffer(pukeBuffer);

	puke1Buffer.loadFromFile("Sounds/Bleugh.wav");
	puke1Music.setBuffer(puke1Buffer);

	puke2Buffer.loadFromFile("Sounds/Burp.wav");
	puke2Music.setBuffer(puke2Buffer);

	howDareYouBuffer.loadFromFile("Sounds/Howdareyou.wav");
	howDareYouMusic.setBuffer(howDareYouBuffer);

	itsGodzillaBuffer.loadFromFile("Sounds/ItGodzilla.wav");
	itsGodzillaMusic.setBuffer(itsGodzillaBuffer);

	endingMoveBuffer.loadFromFile("Sounds/rocketThrow.wav");
	endingMoveMusic.setBuffer(endingMoveBuffer);

	niceShotBuffer.loadFromFile("Sounds/niceshot.wav");
	niceShotMusic.setBuffer(niceShotBuffer);

	eatThisBuffer.loadFromFile("Sounds/eatThis.wav");
	eatThisMusic.setBuffer(eatThisBuffer);

	winnerBuffer.loadFromFile("Sounds/winner.wav");
	winnerMusic.setBuffer(winnerBuffer);

	ohMyGodBuffer.loadFromFile("Sounds/Ohmygod.wav");
	ohMyGodMusic.setBuffer(ohMyGodBuffer);

	bombBangBuffer.loadFromFile("Sounds/Bombbang.wav");
	bombBangMusic.setBuffer(bombBangBuffer);

	hahaBuffer.loadFromFile("Sounds/Haha.wav");
	hahaMusic.setBuffer(hahaBuffer);


	fartBuffer.loadFromFile("Sounds/fart.wav");
	fartMusic.setBuffer(fartBuffer);

	whatsgoinBuffer.loadFromFile("Sounds/Whatsgoin.wav");
	whatsgoinMusic.setBuffer(whatsgoinBuffer);

	switchBuffer.loadFromFile("Sounds/switch.wav");
	switchMusic.setBuffer(switchBuffer);

	selectedBuffer.loadFromFile("Sounds/selected.wav");
	selectedMusic.setBuffer(selectedBuffer);

	levelSsoundBuffer.loadFromFile("Sounds/Levelselected.wav");
	levelSsoundMusic.setBuffer(levelSsoundBuffer);

	p1Buffer.loadFromFile("Sounds/Player1.wav");
	p1Music.setBuffer(p1Buffer);

	p2Buffer.loadFromFile("Sounds/Player2.wav");
	p2Music.setBuffer(p2Buffer);

	fightsoundBuffer.loadFromFile("Sounds/Fight.wav");
	fightMusic.setBuffer(fightsoundBuffer);
	
	mainMMusic.openFromFile("Sounds/mainMusic.wav");
}
void SoundManager::carBounce()
{
	carBounceMusic.play();
}
void SoundManager::carOww()
{
	carOwwMusic.play();
}
void SoundManager::stopIt()
{
	stopItMusic.play();
}
void SoundManager::leaveUsAlone()
{
	leaveUsAloneMusic.play();
}
void SoundManager::somebodySaveUs()
{
	somebodySaveUsMusic.play();
}
void SoundManager::helpMe()
{
	helpMeMusic.play();
}
void SoundManager::scream()
{
	screamMusic.play();
}
void SoundManager::bombsAway()
{
	bombsAwayMusic.play();
}
void SoundManager::puke()
{
	pukeMusic.play();
}
void SoundManager::puke2()
{
	puke1Music.play();
}
void SoundManager::puke3()
{
	puke2Music.play();
}
void SoundManager::howDareYou()
{
	howDareYouMusic.play();
}
void SoundManager::itsGodzilla()
{
	itsGodzillaMusic.play();
}
void SoundManager::endingMove()
{
	endingMoveMusic.play();
}
void SoundManager::ohMyGod()
{
	ohMyGodMusic.play();
}
void SoundManager::eatThis()
{
	eatThisMusic.play();
}
void SoundManager::niceShot()
{
	niceShotMusic.play();
}
void SoundManager::winner()
{
	winnerMusic.play();
}
void SoundManager::bombBang()
{
	bombBangMusic.play();
}
void SoundManager::whatsGoin()
{
	whatsgoinMusic.play();
}
void SoundManager::haHa()
{
	hahaMusic.play();
}
void SoundManager::fart()
{
	fartMusic.play();
}
void SoundManager::choose()
{
	switchMusic.play();
}
void SoundManager::selected()
{
	selectedMusic.play();
}
void SoundManager::mainMusic()
{
	mainMMusic.setVolume(50);
	mainMMusic.play();
	mainMMusic.setLoop(true);
}
void SoundManager::levelSsound()
{
	levelSsoundMusic.play();

}
void SoundManager::p1Sound()
{
	p1Music.play();

}
void SoundManager::p2Sound()
{
	p2Music.play();

}
void SoundManager::fight()
{
	fightMusic.play();

}