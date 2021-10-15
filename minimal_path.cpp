#include <iostream>
#include <vector>
#include <queue>

class Graph
{
private:
    int v; 
    std::vector<std::vector<int>> adjacency_list;
    std::vector<bool> visited;
    int min_num_of_edges;

public:

    Graph(int v)
    {
        this->v = v;
        
        adjacency_list.resize(v);

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        min_num_of_edges = 9999;
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
    }

    void DFS(int start, int end, int current_num_of_edges)
    {
        if (start == end)
        {
            if (current_num_of_edges < min_num_of_edges)
                min_num_of_edges = current_num_of_edges;
            
            return;
        }

        visited[start] = true;

        for (auto node : adjacency_list[start])
        {
            if (!visited[node])
            {
                DFS(node, end, current_num_of_edges + 1);
            }
        }

        visited[start] = false;
    }

    int get_min_num_of_edges()
    {
        return min_num_of_edges;
    }

};

int main ()
{
  int u, v;

  std::cin >> u >> v;

  Graph g(5);

  g.add_edge(0, 1);
  g.add_edge(1, 0);
  g.add_edge(0, 4);
  g.add_edge(4, 0);
  g.add_edge(1, 2);
  g.add_edge(2, 1);
  g.add_edge(2, 4);
  g.add_edge(4, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 2);
  g.add_edge(3, 4);
  g.add_edge(4, 3);

//   g.add_edge(0, 1);
//   g.add_edge(0, 4);
//   g.add_edge(1, 2);
//   g.add_edge(2, 4);
//   g.add_edge(2, 3);
//   g.add_edge(4, 3);

  g.DFS(u, v, 0);

  std::cout << g.get_min_num_of_edges() << "\n";

  return 0;
}
