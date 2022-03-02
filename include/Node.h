#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include "olcPixelGameEngine.h"

struct Node {
	float px, py;
    float radius;
    int id;
    bool path = false;
};

struct dNode {
    int u, dist;
    friend bool operator < (const dNode& l, const dNode& r) {
        return l.dist > r.dist;
    }
};

#endif