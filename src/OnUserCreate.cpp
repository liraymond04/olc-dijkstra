#include "Game.h"

bool Game::OnUserCreate() {
	// Construct Map
	// sMap.resize(vMapSize.x * vMapSize.y, '.');
	// vecSimulationSteps.push_back(sMap);

	sprMouse = new olc::Sprite("assets/cursor.png");

	return true;
}