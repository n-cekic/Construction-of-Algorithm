#include <iostream>
#include <queue>
#include <vector>

class Graph
{
private:
    int v;
    std::vector<int> visited;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<int> parrents;

public:

    Graph(int v)
    {
        this->v = v;

        adjacency_list.resize(v);

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        parrents.resize(v);
        std::fill(parrents.begin(), parrents.end(), -1);
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    bool BFS(int start)
    {
        std::queue<int> nodes;

        visited[start] = true;

        nodes.push(start);

        int pom;

        while(!nodes.empty())
        {
            pom = nodes.front();
            nodes.pop();

            for (auto node : adjacency_list[pom])
            {
                if (!visited[node])
                {
                    visited[node] = true;
                    parrents[node] = pom;
                    nodes.push(node);
                }
                else if (parrents[pom] != node)
                    return true;
            }
        }
        return false;
    }
};

int main ()
{
  Graph g(4);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 3);

  // Graph g(3);
  // g.add_edge(0, 1);
  // g.add_edge(1, 2);

  std::cout << g.BFS(0) << std::endl;

  return 0;
}