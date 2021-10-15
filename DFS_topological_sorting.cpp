#include <iostream>
#include <vector>
#include <stack>

class Graph
{
    int v;
    std::vector<int> visited;
    std::stack<int> stack;
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

    void DFS(int u)
    {
        visited[u] = true;

        for (auto node : adjacency_list[u])
        {
            if (!visited[node])
                DFS(node);
        }

        stack.push(u);
    }

    void topological_sorting()
    {
        for (int i = 0; i < v; i ++)
        {
            if(!visited[i])
                DFS(i);
        }

        while (!stack.empty())
        {
            std::cout << stack.top() << " ";
            stack.pop();
        }

        std::cout << "\n";
    }

};

int main ()
{
  Graph g(6);

  // g.add_edge(5, 2);
  // g.add_edge(5, 0);
  // g.add_edge(4, 0);
  // g.add_edge(4, 1);
  // g.add_edge(2, 3);
  // g.add_edge(3, 1);

  g.add_edge(0, 1);
  g.add_edge(1, 4);
  g.add_edge(2, 4);
  g.add_edge(3, 0);
  g.add_edge(3, 2);
  g.add_edge(5, 2);
  g.add_edge(5, 4);

  g.topological_sorting();

  return 0;
}