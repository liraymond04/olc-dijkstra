#include "Game.h"
#include <unordered_set>

void Game::SimulationStep() {
	if (nSimulationStep >= vecShortestPath.size()) {
		vecNodes[vecShortestPath[nSimulationStep-1]].path = false; 
		bSimulationPlay = false;
		return;
	}
	if (nSimulationStep > 0) {
		vecNodes[vecShortestPath[nSimulationStep-1]].path = false; 
	}
	vecNodes[vecShortestPath[nSimulationStep]].path = true; 
	nSimulationStep++;
}