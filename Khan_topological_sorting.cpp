#include <iostream>
#include <vector>
#include <queue>
class Graph
{
    int v;
    std::vector<int> visited;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<int> node_degree;

public:

    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(v);

        node_degree.resize(v);
        std::fill(node_degree.begin(), node_degree.end(), 0);
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);

        node_degree[v]++;
    }

    void khan()
    {
        std::queue<int> nodes;

        for (int i = 0; i < v; i++)
        {
            if(node_degree[i] == 0)
                nodes.push(i);
        }

        int tmp;

        while (!nodes.empty())
        {
            tmp = nodes.front();

            nodes.pop();

            std::cout << tmp << " ";

            for (auto node : adjacency_list[tmp])
            {
                node_degree[node]--;

                if (node_degree[node] == 0)
                    nodes.push(node);
            }
        }

        std::cout << "\n";
    }

};


int main ()
{
  Graph g(6);

  g.add_edge(0, 1);
  g.add_edge(1, 4);
  g.add_edge(2, 4);
  g.add_edge(3, 0);
  g.add_edge(3, 2);
  g.add_edge(5, 2);
  g.add_edge(5, 4);

  g.khan();

  return 0;
}