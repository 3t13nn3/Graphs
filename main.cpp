#include <iostream>

#include "Graph.hpp"

int main() {
    // Exemple du cours (graph de Dijkstra)
    gr::Graph g(8);

    g.AddEdge(0, 1, 9);
    g.AddEdge(0, 5, 14);
    g.AddEdge(0, 6, 15);

    g.AddEdge(1, 2, 24);

    g.AddEdge(2, 7, 19);
    g.AddEdge(2, 4, 2);

    g.AddEdge(3, 2, -6);
    g.AddEdge(3, 7, 6);

    g.AddEdge(4, 3, 11);
    g.AddEdge(4, 7, 16);

    g.AddEdge(5, 2, 18);
    g.AddEdge(5, 4, 30);

    g.AddEdge(6, 4, 20);
    g.AddEdge(6, 7, 44);

    // g.Print();

    int start = 0;
    int end = 7;

    std::cout << "DIJKSTRA Path from " << start << " to " << end << ":"
              << std::endl;
    int cost = g.Dijkstra(start, end);
    std::cout << "Cost: " << cost << std::endl << std::endl;

    std::cout << "BELLMAN FORD Path from " << start << " to " << end << ":"
              << std::endl;

    bool cycle;
    cost = g.BellmanFord(start, end, cycle);
    std::cout << "Cost: " << cost << " Cycle: " << cycle << std::endl
              << std::endl;

    // adding a negative cycle to test Bellman Ford
    g.AddEdge(3, 2, -187);

    std::cout << "BELLMAN FORD Path from " << start << " to " << end << ":"
              << std::endl;

    cost = g.BellmanFord(start, end, cycle);
    std::cout << "Cost: " << cost << " Cycle: " << cycle << std::endl;

    exit(0);
}
