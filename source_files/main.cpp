#include "../header_files/Header.h"
#include "../header_files/Game.h"

#include <Windows.h>

bool show_hitbox = false;
std::ofstream fout("log.txt");

int main(int argc, char* argv[])
{
	Game game;
	
	if (argc != 1) show_hitbox = true;
    try 
	{
      	game.run();
    }
    catch (const std::exception& e) 
	{
      	fout << "Exception: " << e.what() << '\n';
	}
	//system("pause");
	return 0;
}
