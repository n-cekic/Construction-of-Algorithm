#include <iostream>
#include <vector>
#include <queue>


class Graph
{
private:
    int v;
    std::vector<bool> visited;
    std::vector<std::vector<int>> list;

public:
   
    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        list.resize(v);
    }

    void add_edge(int u, int v)
    {
        list[u].push_back(v);
    }

    void bfs(int u)
    {
        std::queue<int> nodes;

        nodes.push(u);
        visited[u] = true;

        int pom;
        while(!nodes.empty())
        {
            pom = nodes.front();

            nodes.pop();

            std::cout << pom << " ";

            for(auto n : list[pom])
            {
                if(!visited[n])
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

  Graph g(5);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(0, 3);
  g.add_edge(1, 4);
  g.add_edge(2, 3);
  g.add_edge(2, 4);
  g.add_edge(3, 1);
  g.add_edge(4, 2);
  g.add_edge(4, 1);

  g.bfs(v);

  return 0;
}