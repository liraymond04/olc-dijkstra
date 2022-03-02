#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "olcPixelGameEngine.h"

// TODO
/*
	Remove edges
	Select edge direction
	Edge weight
*/

struct Edge {
	int si, ei;
	float radius;
	int id;
	int w = 1;
};

struct dEdge {
	int u, v, w;
	int id;
	friend bool operator < (const dEdge& l, const dEdge& r) {
       return l.w < r.w;
    }
};

#endif