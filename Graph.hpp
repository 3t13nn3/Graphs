#include <iostream>
#include <list>
#include <queue>
#include <vector>

#define INF 0XFFFFFFF

namespace gr {
class Graph {
   public:
    Graph(int size);

    void AddEdge(int a, int b, int c);

    void Print();

    int Dijkstra(int start, int end);

    int BellmanFord(int start, int end, bool& cycle);

   private:
    std::vector<std::list<std::pair<int, int>>> adj;  // name, value, weight

    void fillPath(std::vector<int> parent, int idx, std::vector<int>& path);
};
}  // namespace gr
