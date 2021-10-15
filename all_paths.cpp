#include <iostream>
#include <stack>
#include <vector>

class Graph
{
private:
    int v;
    std::vector<bool> visited;
    std::vector<std::vector<int>> adjacency_list;
    bool path_found;
public:
   
    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(v);

        path_found = false;
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    void DFS(int start, int end, std::vector<int> path)
    {
        if (start == end)
        {           
            path.push_back(end);

            for(auto n : path)
                std::cout << n << " ";
            std::cout << std::endl;

            return ;
        }

            path.push_back(start);
            visited[start] = true;

        for (auto node : adjacency_list[start])
        {
            if(!visited[node])
                DFS(node, end, path);
        }

        visited[start] = false;
    }
};

int main ()
{
  int u, v;

  std::cin >> u >> v;

  Graph g(7);

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 4);
  g.add_edge(1, 3);
  g.add_edge(3, 4);
  g.add_edge(0, 2);

  std::vector<int> result;

  g.DFS(u, v, result);

  return 0;
}
