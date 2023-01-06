#include "include/common/Game.h"
#include "include/ui/CommandLineInterface.h"

int main(int, const char* [])
{
    CommandLineInterface userInterface;
    Game game(userInterface);
    game.Run();
	
	return 0;
}
