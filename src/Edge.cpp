#include "Game.h"

void Game::AddEdge(Node* a, Node* b, float r) {
    Edge n;
    n.si = a->id; n.ei = b->id;
    n.radius = r;
    n.id = sEdgesSize++;
    adj[a->id].push_back({a->id, b->id, n.w, n.id});
    adj[b->id].push_back({b->id, a->id, n.w, n.id});
    vecEdges[n.id] = n;
}

void Game::RemoveEdge(int id) {
    Edge &cur = vecEdges[id];
    for (auto it = adj[cur.si].cbegin(); it != adj[cur.si].cend();) {
        if (it->id == id) {
            it = adj[cur.si].erase(it);
        } else {
            ++it;
        }
    }
    for (auto it = adj[cur.ei].cbegin(); it != adj[cur.ei].cend();) {
        if (it->id == id) {
            it = adj[cur.ei].erase(it);
        } else {
            ++it;
        }
    }
    vecEdges.erase(id);
    // erase from adj
}