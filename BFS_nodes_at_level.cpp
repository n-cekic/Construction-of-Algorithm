#include <iostream>
#include <queue>
#include <vector>

class Graph
{
private:
    int v;
    std::vector<int> visited;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<int> node_i_is_at_level;

public:

    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(v);

        node_i_is_at_level.resize(v);
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
    }

    void BFS(int root, int level)
    {
        std::queue<int> nodes;

        visited[root] = true;
        nodes.push(root);

        int pom;

        node_i_is_at_level[root] = 0;

        while (!nodes.empty())
        {
            pom = nodes.front();
            nodes.pop();

            for (auto node : adjacency_list[pom])
            {
                if (!visited[node])
                {
                    visited[node] = true;
                    nodes.push(node);
                    node_i_is_at_level[node] = node_i_is_at_level[pom] + 1;
                }
            }
        }

        int counter = 0;

        for (auto lvl : node_i_is_at_level)
        {
            if (lvl == level)
                counter++;
        }

        std::cout << counter << "\n";

    }


};

int main ()
{
  Graph g(8);

  g.add_edge(0, 1);
  g.add_edge(0, 4);
  g.add_edge(0, 7);
  g.add_edge(4, 6);
  g.add_edge(4, 5);
  g.add_edge(4, 2);
  g.add_edge(7, 3);

  int level;

  std::cin >> level;

  g.BFS(0, level);

  return 0;
}
