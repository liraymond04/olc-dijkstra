#include "Game.h"

// TODO
/*
	Load background image

	Serialize node and edge data to file
	Read and load serialized data
	
	Pan and zoom

	Simulate and play path
	Show table of values (visualize algorithm)
	Print string for shortest path

	Create terminal, developer console
	Interpret commands to change data
*/

int main() {
	// ShowCursor(false);

	Game game;

	if (game.Construct(512, 384, 2, 2))
		game.Start();
	else
		wcout << L"Could not construct console" << endl;

	return 0;
}