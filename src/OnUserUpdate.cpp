#include "Game.h"

bool Game::OnUserUpdate(float fElapsedTime) {
	if (GetKey(olc::ESCAPE).bPressed) return false;

	HandleInput(fElapsedTime);
	HandleSimulationPlay(fElapsedTime);
	Draw();

	return true;
}