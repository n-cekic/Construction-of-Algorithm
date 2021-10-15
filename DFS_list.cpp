#include <iostream>
#include <vector>
#include <stack>

class Graph
{
private:

    int v;
    std::vector<int> visited;
    std::vector<std::vector<int>> list;

public:

    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        fill(visited.begin(), visited.end(), false);

        list.resize(v);
    }

    void add_edge(int u, int v)
    {
        list[u].push_back(v);
        list[v].push_back(u);
    }

    void DFS(int u)
    {
        std::stack<int> nodes;

        nodes.push(u);
        visited[u] = true;

        int pom;

        while (!nodes.empty())
        {
            pom = nodes.top();

            nodes.pop();

            std::cout << pom << " ";

            for (auto n : list[pom])
            {
                if (!visited[n])
                {
                    nodes.push(n);
                    visited[n] = true;
                }
            }
        }
    }
};

int main ()
{
    int v;

    std::cin >> v;

    Graph g(6);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(2, 5);

    g.DFS(v);

    std::cout << "\n";

    return 0;
}
