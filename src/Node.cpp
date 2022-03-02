#include "Game.h"

void Game::AddNode(float x, float y, float r) {
	Node b;
	b.px = x; b.py = y;
	b.radius = r;
	b.id = sNodesSize++;
	vecNodes[b.id] = b;
    adj[b.id] = {};
}

void Game::RemoveNode(int id) {
	vecNodes.erase(id);
	for (auto &edge : adj[id]) {
		RemoveEdge(edge.id);
	}
	adj.erase(id);
}