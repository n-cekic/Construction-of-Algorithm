#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

class Graph
{
private:

    int v;
    std::vector<bool> visited;
    std::vector<std::vector<int>> adjacency_list;

public:

    Graph(int v)
    {
        this->v = v;

        visited.resize(v);

        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(v);
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
    }

    void BFS(int u)
    {
        std::queue<int> nodes;

        nodes.push(u);
        visited[u] = true;

        int pom;

        while (!nodes.empty())
        {
            pom = nodes.front();

            nodes.pop();
            std::cout << pom << " ";
            for (auto node : adjacency_list[pom])
            {
                if (!visited[node])
                {
                    visited[node] = true;
                    nodes.push(node);
                }
            }
        }

        std::cout << std::endl;
        
    }

    int num_of_components()
    {
        int noc = 0;
        for (int  i = 0; i < v; i++)
        {
            if (visited[i] == false)
            {   BFS(i);
                noc++;
            }
        }
        return noc;
    }
};


int main ()
{
    Graph g(10);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.add_edge(4, 5);
    g.add_edge(4, 4);

    int noc = g.num_of_components();
    std::cout << "Number of components: " << noc << "\n";

    return 0;
}
