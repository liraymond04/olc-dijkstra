#include "Game.h"

#include <queue>
#include <limits.h>

void Game::ComputePath() {
    if (pSimulationStart == -1 || pSimulationEnd == -1) {
        return;
    }

    int n = adj.size();

    priority_queue<dNode> pq;
    pq.push({pSimulationStart, 0});

    unordered_map<int, bool> visited;

    unordered_map<int, int> result;
    unordered_map<int, pair<int, int> > parent;
    for (auto &cur : adj) {
        result[cur.first] = INT_MAX;
        parent[cur.first] = {-1, -1};
    }

    result[pSimulationStart] = 0;

    while (!pq.empty()) {
        dNode cur = pq.top();
        pq.pop();

        int u = cur.u;
        if (u == pSimulationEnd) {
            break;
        }
        visited[u] = true;

        for (const dEdge &edge : adj[u]) {
            int dist = cur.dist + edge.w;
            if (dist < result[edge.v] && !visited[edge.v]) {
                pq.push({edge.v, dist});
                result[edge.v] = dist;
                parent[edge.v] = {u, edge.id};
            }
        }
    }

    TraversePath(parent, pSimulationEnd);
    reverse(vecShortestPath.begin(), vecShortestPath.end());
}

void Game::TraversePath(unordered_map<int, pair<int, int> > &parent, int i) {
    mapShortestPath[parent[i].second] = true;
    vecShortestPath.push_back(i);
    if (parent[i].first == -1) {
        return;
    }
   
    TraversePath(parent, parent[i].first);
}