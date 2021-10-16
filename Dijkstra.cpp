#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <stack>

#define INFINITY 99999

struct compare
{
    bool operator()(std::pair<int, int> &p1, std::pair<int, int> &p2)
    {
        return p1.first > p2.first;
    }
};


class Graph
{
private:
    int v; 
   // std::vector<int> parrents;
    std::vector<int> distances;
    std::vector<int> shortest_path;
    std::vector<bool> path_found;
    std::vector<std::vector<std::pair<int, int>>> adjacency_list;

public:

    Graph(int v)
    {
        this->v = v;

        distances.resize(v);
        std::fill(distances.begin(), distances.end(), INFINITY);

        shortest_path.resize(v);
        std::fill(shortest_path.begin(), shortest_path.end(), INFINITY);

        path_found.resize(v);
        std::fill(path_found.begin(), path_found.end(), false);

        adjacency_list.resize(v);
    }

    void add_edge(int u, int v, int weight)
    {
        adjacency_list[u].push_back(std::make_pair(v, weight));
        adjacency_list[v].push_back(std::make_pair(u, weight));
    }

    int dijkstra(int u, int v)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> heap;
        
        distances[u] = 0;

        heap.push(std::make_pair(distances[u], u));

        std::pair<int, int> temp;

        while (!heap.empty())
        {
            temp = heap.top();

            heap.pop();

            if(path_found[temp.second])
                continue;

            path_found[temp.second] = true;

            for (std::pair<int, int> &neighbour : adjacency_list[temp.second])
            {
                if (!path_found[neighbour.first]
                    && distances[neighbour.first] > distances[temp.second] + neighbour.second)
                {   
                    distances[neighbour.first] = distances[temp.second] + neighbour.second;

                    heap.push(std::make_pair(distances[neighbour.first], neighbour.first));
                }
            }
        }

        for (int i = 0; i < this->v; i++)
            std::cout << i << " " << distances[i] << "\n";
    
    
        return distances[v];
    }


};

int main ()
{
    Graph g(9);

    // g.add_edge(0, 1, 1);
    // g.add_edge(1, 2, 4);
    // g.add_edge(2, 3, 7);
    // g.add_edge(3, 4, 2);
    // g.add_edge(4, 0, 10);

    //    (od, do, tezina);

    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(1, 2, 8);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(7, 8, 7);
    g.add_edge(7, 6, 1);
    g.add_edge(8, 6, 6);
    g.add_edge(2, 5, 4);
    g.add_edge(6, 5, 2);
    g.add_edge(3, 5, 14);
    g.add_edge(3, 4, 9);
    g.add_edge(4, 5, 10);


    std::cout << g.dijkstra(0, 6) << "\n";

    return 0;
}
