#include "../HeaderFiles/Header.h"
#include "../HeaderFiles/Game.h"

#include <Windows.h>

int main()
{
	Game game;

	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	game.run();

	//system("pause");
	return 0;
}
