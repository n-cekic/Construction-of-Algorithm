#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class Graph
{
    int v;
    std::vector<bool> visited;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<int> parrents;

public:

    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(v);

        parrents.resize(v);
        std::fill(parrents.begin(), parrents.end(), -1);
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    void BFS(int u, int v)
    {
        std::queue<int> nodes;

        visited[u] = true;

        nodes.push(u);

        int pom;

        while (!nodes.empty() && pom != v)
        {
            pom = nodes.front();

            nodes.pop();
            
            for (auto node : adjacency_list[pom])
            {
                if(!visited[node])
                {
                    visited[node] = true;
                    nodes.push(node);
                    parrents[node] = pom;
                }
            }
        }

        // for (int i = 0; i < this->v; i++)
        //     std::cout << i << ">" << parrents[i] << "\n";

        // std::cout << "\n";
    }

    void find_shortest_path(int u, int v)
    {
        BFS(u, v);
        std::vector<int> path;
        while (v != -1)
        {
            path.push_back(v);
            v = parrents[v];
        }

        std::for_each(path.rbegin(),
                path.rend(),
                [](const auto &c) {
                    std::cout << c << " ";
                });
        
    }

};

int main ()
{
  Graph g(8);

  g.add_edge(0, 1);
  g.add_edge(0, 3);
  g.add_edge(1, 2);
  g.add_edge(3, 4);
  g.add_edge(3, 7);
  g.add_edge(4, 5);
  g.add_edge(4, 6);
  g.add_edge(4, 7);
  g.add_edge(5, 6);
  g.add_edge(6, 7);

  int u, v;

  std::cin >> u >> v;

  g.find_shortest_path(u, v);

  return 0;
}
