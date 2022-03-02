#include "Game.h"

void Game::Draw() {
	Clear(olc::BLACK);
	SetPixelMode(olc::Pixel::MASK);

	// Draw Lines
	for (auto &cur : vecEdges) {
		Edge &edge = cur.second;
		float sx = vecNodes[edge.si].px, sy = vecNodes[edge.si].py;
		float ex = vecNodes[edge.ei].px, ey = vecNodes[edge.ei].py;
		float nx = -(ey - sy);
		float ny = (ex - sx);
		float d = sqrt(nx*nx + ny * ny);
		nx /= d;
		ny /= d;

		float midx = (sx + ex) / 2, midy = (sy + ey) / 2;
		FillCircle(midx, midy, edge.radius, olc::WHITE);

		// cout << nx << " " << ny << "\n";

		olc::Pixel col = olc::WHITE;

		if (mapShortestPath[edge.id]) col = olc::YELLOW;

		DrawLine((sx + nx * edge.radius), (sy + ny * edge.radius), (ex + nx * edge.radius), (ey + ny * edge.radius), col);
		DrawLine((sx - nx * edge.radius), (sy - ny * edge.radius), (ex - nx * edge.radius), (ey - ny * edge.radius), col);

		DrawStringDecal({midx - (edge.radius/2), midy - (edge.radius/2)}, to_string(edge.w), olc::BLACK);
	}

	// Draw Balls
	for (auto &cur : vecNodes) {
		Node &node = cur.second;
		olc::Pixel col = olc::WHITE;
		if (node.id == pSimulationStart) col = olc::GREEN;
		if (node.id == pSimulationEnd) col = olc::RED;
		if (bSimulationPlay && node.path) col = olc::YELLOW;
		FillCircle(node.px, node.py, node.radius, col);
		DrawStringDecal({node.px - (node.radius/2), node.py - (node.radius/2)}, to_string(node.id), olc::BLACK);
			// DrawStringDecal({node.px - node.radius, node.py - (node.radius/2)}, ">", olc::BLUE);
	}

	// Draw Cue
	if (pSelectedNode != nullptr) {
		DrawLine(pSelectedNode->px, pSelectedNode->py, vMouse.x, vMouse.y, olc::Pixel(0, 0, 255));
	}

	// Draw table of values

	// Draw Mouse
	// FillCircle(vMouse, 4.0f, olc::RED);
	DrawSprite(vMouse, sprMouse);
}