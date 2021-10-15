#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Graph
{
    int V;
    std::vector<bool> visited;
    int **matrix;
    std::vector<int> in_degrees;
    std::vector<int> topological_sort;


public:

    Graph(int V)
    {
        this->V = V;

        visited.resize(V);
        std::fill(visited.begin(), visited.end(), false);


        matrix = (int **)malloc(V * sizeof(int *));

        for (int i = 0; i < V; i++)
            matrix[i] = (int *)calloc(V, sizeof(int));


        in_degrees.resize(V);
        std::fill(in_degrees.begin(), in_degrees.end(), 0);
    }

    void add_edge(int u, int v)
    {
        matrix[u][v] = 1;

        in_degrees[v]++;
    }

    void topsort()
    {
        std::queue<int> nodes;

        for(int i = 0; i < V; i++)
            if (!in_degrees[i])
                nodes.push(i);

        int tmp;

        while (!nodes.empty())
        {
            tmp = nodes.front();

            nodes.pop();

            topological_sort.push_back(tmp);

            for (int i = 0; i < V; i++)
            {
                if (matrix[tmp][i] != 0){
                    in_degrees[i]--;

                    if (in_degrees[i] == 0)
                        nodes.push(i);
                }
            }
        }
    }

    bool has_hamilton_path()
    {
        topsort();

        for (int i = 0; i < V; i++)
        {
            if (matrix[topological_sort[i]][topological_sort[i+1]] == 0)
                return false;
        }
        return true;
    }


};

    int main ()
    {
    Graph g(4);

    // Ima
    // g.add_edge(0, 1);
    // g.add_edge(1, 2);
    // g.add_edge(2, 3);

    // Nema
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(0, 3);

    std::cout << (g.has_hamilton_path() ? "Graph has Hamiltonian path! :)\n" : "Graph doesn't have Hamiltonian path! :(\n");

    return 0;
    }
