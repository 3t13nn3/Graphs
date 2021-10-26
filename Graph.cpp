#include "Graph.hpp"

using namespace gr;

Graph::Graph(int size) { adj.resize(size); }

void Graph::AddEdge(int a, int b, int c) {
    adj[a].emplace_back(std::make_pair(b, c));
}

void Graph::Print() {
    for (size_t(i) = 0; i < adj.size(); ++i) {
        std::cout << i << ":" << std::endl;
        for (const auto& l : adj[i]) {
            std::cout << "<> " << l.first << " | " << l.second << std::endl;
        }
    }
}

int Graph::Dijkstra(int start, int end) {
    std::vector<int> dist(adj.size(), INF);

    std::vector<int> prev(adj.size(), -1);

    // Priority queue with greter put the lowst element on the top
    // Using this data struct got a better complexity than set
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        queue;

    // node we begin the path
    dist[start] = 0;
    // inserting the start node into the queue, with dist of 0
    queue.push(std::make_pair(0, start));

    while (!queue.empty()) {
        // extract the minimum distance of the queue and remove it
        std::pair<int, int> cur = queue.top();
        queue.pop();

        int u = cur.second;

        for (const auto& e : adj[u]) {
            int v = e.first;
            int weight = e.second;

            if (dist[v] > dist[u] + weight) {
                // assigning new dist for v node
                dist[v] = dist[u] + weight;
                queue.push(std::make_pair(dist[v], v));
                // keep parent
                prev[v] = u;
            }
        }
    }

    std::vector<int> path(1, start);
    fillPath(prev, end, path);

    for (const int& e : path) {
        std::cout << " -> " << e;
    }
    std::cout << std::endl;

    return dist[end];
}

int Graph::BellmanFord(int start, int end, bool& cycle) {
    cycle = false;
    std::vector<int> dist(adj.size(), INF);

    std::vector<int> prev(adj.size(), -1);

    dist[start] = 0;

    // We loop n-1x through all nodes
    for (size_t i(0); i < adj.size() - 1; ++i) {
        // to compare them to theire childs
        for (size_t u(0); u < adj.size(); ++u) {
            // don't need to check not visited node because we don't know
            // how to reach them
            if (dist[u] != INF) {
                // for each childs
                for (const auto& e : adj[u]) {
                    int v = e.first;
                    int weight = e.second;
                    // relaxation
                    if (dist[v] > dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                        // keep parents for the path
                        prev[v] = u;
                    }
                }
            }
        }
    }

    // checking negative cycle
    for (size_t u(0); u < adj.size(); ++u) {
        for (const auto& e : adj[u]) {
            int v = e.first;
            int weight = e.second;
            // a negative cycle is defined when the init node "u" + the
            // weight of the target node "v" is lower than "v" (the case is
            // that "u" had a negative weight beetween "v" and "u", that
            // make "v" lower than "u" on the second pass)
            if (dist[u] + weight < dist[v]) {
                cycle = true;
            }
        }
    }

    if (!cycle) {
        std::vector<int> path(1, start);
        fillPath(prev, end, path);

        for (const int& e : path) {
            std::cout << " -> " << e;
        }
        std::cout << std::endl;
    }

    return dist[end];
}

void Graph::fillPath(std::vector<int> parent, int idx, std::vector<int>& path) {
    if (parent[idx] == -1) {
        return;
    }

    fillPath(parent, parent[idx], path);
    path.emplace_back(idx);
}