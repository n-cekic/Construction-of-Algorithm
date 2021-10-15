#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>

class Graph
{
private:
    
    int V;
    int **matrix;
    std::vector<bool> visited;

public:
    
    Graph( int V)
    {
        this->V = V;

        visited.resize(V);

        std::fill(visited.begin(), visited.end(), false);

        matrix = (int**)malloc(V * sizeof(int*));

        for(int i = 0; i < V; i++)
            matrix[i] = (int*)calloc(V, sizeof(int));
    }

    ~Graph()
    {
        for(int i = 0; i < this->V; i++)
            free(matrix[i]);
        free(matrix);
    }

    void add_edge(int u, int v)
    {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void BFS (int u)
    {
        std::queue<int> nodes; 

        nodes.push(u);

        visited[u] = true;
        int pom;

        while (!nodes.empty())
        {
            pom = nodes.front();
            nodes.pop();
            std::cout << pom << " ";

            for (int i = 0; i < V; i++)
            {
                if  (matrix[pom][i] && !visited[i])
                {
                    visited[i] = true;
                    nodes.push(i);
                }
            }
        }

        std::cout << std::endl;
    }
};


int main ()
{
  int v;

  std::cin >> v;

  Graph g(6);

//   g.add_edge(0, 1);
//   g.add_edge(0, 2);
//   g.add_edge(1, 2);
//   g.add_edge(2, 0);
//   g.add_edge(2, 3);
//   g.add_edge(3, 3);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(2, 5);

  g.BFS(v);

  return 0;
}