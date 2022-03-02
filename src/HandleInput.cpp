#include "Game.h"

void Game::HandleInput(float fElapsedTime) {
	auto IsPointInCircle = [](float x1, float y1, float r1, float px, float py) {
		return fabs((x1 - px)*(x1 - px) + (y1 - py)*(y1 - py)) < (r1 * r1);
	};

	/* Mouse Handle */
	vMouse = {float(GetMouseX()), float(GetMouseY())};

	// Flag to compute shortest path if graph is updated
	bool bIsGraphUpdated = false;

	// Make Edge connections with left click
	if (GetMouse(0).bPressed && 
		!(GetKey(olc::Key::SHIFT).bHeld || GetKey(olc::Key::CTRL).bHeld ||
		  GetKey(olc::S).bHeld || GetKey(olc::E).bHeld || 
		  GetKey(olc::D).bHeld)) {
		if (bSelectedEdgeStart) {
			for (auto &cur : vecNodes) {
				Node &node = cur.second;
				if (IsPointInCircle(node.px, node.py, node.radius, vMouse.x, vMouse.y)) {
					AddEdge(pSelectedNode, &node, fEdgeRadius);
					pSelectedNode = &node;
					bSelectedEdgeStart = false;
					bIsGraphUpdated = true;
					break;
				}
			}
		}

		bSelectedEdgeStart = false;
		
		pSelectedNode = nullptr;
		for (auto &cur : vecNodes) {
			Node &node = cur.second;
			if (IsPointInCircle(node.px, node.py, node.radius, vMouse.x, vMouse.y)) {
				pSelectedNode = &node;
				bSelectedEdgeStart = true;
				break;
			}
		}
	}

	// Place Node with right click or shift left click
	if (GetMouse(1).bPressed || (GetKey(olc::Key::SHIFT).bHeld && GetMouse(0).bPressed)) {
		AddNode(vMouse.x, vMouse.y, fNodeRadius);
	}

	// Set start node with S left click
	if (GetKey(olc::S).bHeld && GetMouse(0).bPressed) {
		for (auto &cur : vecNodes) {
			Node &node = cur.second;
			if (IsPointInCircle(node.px, node.py, node.radius, vMouse.x, vMouse.y)) {
				if (node.id == pSimulationEnd) break;
				if (node.id == pSimulationStart) {
					pSimulationStart = -1;
					vecShortestPath.clear();
					mapShortestPath.clear();
					break;
				} else {
					pSimulationStart = node.id;
					if (pSimulationStart != -1 && pSimulationEnd != -1) {
						bIsGraphUpdated = true;
					}
					break;
				}
			}
		}
	}

	// Set end node with E left click
	if (GetKey(olc::E).bHeld && GetMouse(0).bPressed) {
		for (auto &cur : vecNodes) {
			Node &node = cur.second;
			if (IsPointInCircle(node.px, node.py, node.radius, vMouse.x, vMouse.y)) {
				if (node.id == pSimulationStart) break;
				if (node.id == pSimulationEnd) {
					pSimulationEnd = -1;
					vecShortestPath.clear();
					mapShortestPath.clear();
					break;
				} else {
					pSimulationEnd = node.id;
					if (pSimulationStart != -1 && pSimulationEnd != -1) {
						bIsGraphUpdated = true;
					}
					break;
				}
			}
		}
	}

	// Delete Node or Edge with D left click
	if (GetKey(olc::D).bHeld && GetMouse(0).bPressed) {
		for (auto &cur : vecNodes) {
			Node &node = cur.second;
			if (IsPointInCircle(node.px, node.py, node.radius, vMouse.x, vMouse.y)) {
				RemoveNode(node.id);
				bIsGraphUpdated = true;
				break;
			}
		}
		for (auto &cur : vecEdges) {
			Edge &edge = cur.second;
			float sx = vecNodes[edge.si].px, sy = vecNodes[edge.si].py;
			float ex = vecNodes[edge.ei].px, ey = vecNodes[edge.ei].py;
			float midx = (sx + ex) / 2, midy = (sy + ey) / 2;
			if (IsPointInCircle(midx, midy, edge.radius, vMouse.x, vMouse.y)) {
				RemoveEdge(edge.id);
				bIsGraphUpdated = true;
				break;
			}
		}
	}

	// Move Node with ctrl left click
	if (GetKey(olc::Key::CTRL).bHeld && GetMouse(0).bHeld) {
		for (auto &cur : vecNodes) {
			Node &node = cur.second;
			if (IsPointInCircle(node.px, node.py, node.radius, vMouse.x, vMouse.y)) {
				node.px = vMouse.x; node.py = vMouse.y;
			}
		}
	}

	if (GetKey(olc::Key::ENTER).bPressed) {
		bSimulationPlay = true && !vecShortestPath.empty();
	}

	if (bIsGraphUpdated) {
		vecShortestPath.clear();
		mapShortestPath.clear();
		ComputePath();
	}

// 	if (GetKey(olc::Key::ENTER).bPressed) {
// 		ComputePath();
// 	}

// 	if (GetKey(olc::Key::BACK).bPressed) {
// 		vecShortestPath.clear();
// 		mapShortestPath.clear();
// 	}
}