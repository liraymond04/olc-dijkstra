#include "Game.h"

void Game::HandleSimulationPlay(float fElapsedTime) {
	if (bSimulationPlay) { // Forward
		fSimulationCounter += (float)nSimulationSpeed * fElapsedTime;
		if (fSimulationCounter >= 1) {
			SimulationStep();
			fSimulationCounter = 0;
		}
	} else {
		fSimulationCounter = 0;
		nSimulationStep = 0;
	}
}