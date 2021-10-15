#include <iostream>
#include <vector>
#include <stack>
class Graph
{
private:
    int **matrix;
    std::vector<bool> visited;
    int v;

public:

    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        fill(visited.begin(), visited.end(), false);

        matrix = (int **)malloc(v * sizeof(int *));

        for (int i = 0; i < v; i++)
            matrix[i] = (int *)calloc(v, sizeof(int));
    }

    ~Graph()
    {
        for(int i = 0; i < v; i++)
            free(matrix[i]);
        free(matrix);
    }

    void add_edge(int u, int  v)
    {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void DFS(int u)
    {
        visited[u] = true;

        std::cout << u << " ";

        for(int i = 0; i < v; i++)
        {
            if(matrix[u][i] && !visited[i])
                    DFS(i);
        }
    }

    void DFS_with_stack(int u)
    {
        std::stack<int> nodes;

        int pom;

        nodes.push(u);

        visited[u] = true;

        while(!nodes.empty())
        {
            pom = nodes.top();

            nodes.pop();

            std::cout << pom << " ";

            for(int i = 0; i < v; i++)
            {
                if(matrix[pom][i] && !visited[i])
                {
                    visited[i] = true;
                    nodes.push(i);
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

  std::cout << std::endl;

  return 0;
}