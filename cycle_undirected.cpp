#include <iostream>
#include <vector>

class Graph
{
private:
    int v;
    std::vector<bool> visited;
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

    bool DFS(int start, int parrent)
    {

        visited[start] = true;

        for (auto node : adjacency_list[start])
        {
            if(visited[node])
            {
                if (node != parrent)
                    return true;
            }
            
            else if (DFS(node, start))
                return true;
        }

        return false;
    }



};


int main ()
{
//   Graph g(4);

//   g.add_edge(0, 1);
//   g.add_edge(0, 2);
//   g.add_edge(1, 2);
//   g.add_edge(2, 3);
//   g.add_edge(3, 3);

  Graph g(3);
  g.add_edge(0, 1);
  g.add_edge(1, 2);

 std::cout << g.DFS(0, -1) << std::endl;

  return 0;
}
