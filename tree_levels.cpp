#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


class Graph
{
    int v;
    std::vector<bool> visited;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<int> node_level;

public:

    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(v);

        node_level.resize(v);
        std::fill(node_level.begin(), node_level.end(), 0);
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    void BFS(int u)
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
                    node_level[node] = node_level[pom] + 1;
                }
            }
        }
        int max = *std::max_element(node_level.begin(), node_level.end());
        for (int l = 0; l <= max; l++ )
        {
            for (int i = 0; i < v; i ++)
            {
                if (node_level[i] == l)
                    std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }

};

int main ()
{
  Graph g(8);

  g.add_edge(2,1);
  g.add_edge(2,3);
  g.add_edge(3,5);
  g.add_edge(5,4);
  g.add_edge(5,7);
  g.add_edge(7,6);
  g.add_edge(1,0);
  
  int u, v;

  g.BFS(2);

  return 0;
}
