#include "../HeaderFiles/Header.h"
#include "../HeaderFiles/Game.h"

#include <Windows.h>

int main()
{
	Game game;

	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);
	sf::Music music;
	music.openFromFile("../build/Audio/background.ogg");
	music.setVolume(50);
	music.play();
	
	game.run();

	//system("pause");
	return 0;
}
