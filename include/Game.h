#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

#include "olcPixelGameEngine.h"

#include "Node.h"
#include "Edge.h"

class Game : public olc::PixelGameEngine {
public:
	Game() {
		sAppName = "Dijkstra's Shortest Path";
	}

	~Game() {
		delete sprMouse;
	}

private:
	/* Nodes and Edges */
	unordered_map<int, Node> vecNodes;
	unordered_map<int, Edge> vecEdges;
	unordered_map<int, vector<dEdge> > adj;
	Node* pSelectedNode = nullptr;
	Edge* pSelectedEdge = nullptr;
	bool bSelectedEdgeStart = false;
	float fNodeRadius = 10.0f;
	float fEdgeRadius = 5.0f;
	int sNodesSize = 0;
	int sEdgesSize = 0;

	int pSimulationStart = -1;
	int pSimulationEnd = -1;

	/* Mouse */
	olc::vf2d vMouse;
	olc::vf2d vMouseCell;
	olc::vi2d vCell;
	olc::Sprite* sprMouse;

	vector<int> vecShortestPath;
	unordered_map<int, bool> mapShortestPath;

	/* Simulation */
	int nSimulationStep = 0;
	float fSimulationCounter = 0;

	int nSimulationSpeed = 1;
	bool bSimulationPlay = false;

public:
	void AddNode(float x, float y, float r);
	void AddEdge(Node* a, Node* b, float r);
	void RemoveNode(int id);
	void RemoveEdge(int id);

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	void HandleInput(float fElapsedTime);
	void Draw();

	void ComputePath();
	void TraversePath(unordered_map<int, pair<int, int> > &parent, int i);

	void HandleSimulationPlay(float fElapsedTime);
	void SimulationStep();
};

#endif // !GAME_H
