#include <iostream>
#include <cstdlib>
#include <vector>

#define INF 9999

class Graph
{
private:
    int V;
    std::vector<bool> connected;
    std::vector<int> edges;
    std::vector<int> parrent;
    int **adjacency_matrix;

public:

    Graph(int V)
    {
        this->V = V;

        connected.resize(V);
        std::fill(connected.begin(), connected.end(), false);

        edges.resize(V);
        std::fill(edges.begin(), edges.end(), INF);

        parrent.resize(V);
        std::fill(parrent.begin(), parrent.end(), -1);

        adjacency_matrix = (int **)malloc(V * sizeof(int*));

        for (int i = 0; i < V; i++)
            adjacency_matrix[i] = (int *)calloc(V, sizeof(int));
        
    }

    void add_edge(int u, int v, int weight)
    {
        adjacency_matrix[u][v] = weight;
        adjacency_matrix[v][u] = weight;
    }

    void prim(int u)
    {
        edges[u] = 0;

        int node;

        for (int i = 0; i < V; i++)
        {
            node = min_edge_not_included();

            connected[node] = true;

            for (int v = 0; v < V; v++)
            {
                if(adjacency_matrix[node][v] 
                && !connected[v] 
                && adjacency_matrix[node][v] < edges[v])
                {
                    parrent[v] = node;
                    edges[v] = adjacency_matrix[node][v];
                }
            }
        }

        int MST_cost = 0;

        for (int i = 1; i < V; i++)
        {
            MST_cost += adjacency_matrix[i][parrent[i]];
        }

        std::cout << MST_cost << std::endl;
    }

    int min_edge_not_included()
    {
        int min = INF;
        int min_index = -1;

        for (int i = 0; i < V; i++)
        {
            if (!connected[i] && edges[i] < min)
            {
                min = edges[i];
                min_index = i;
            }
        }

        return min_index;
    }

};

int main ()
{
    Graph g(5);

    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 2);
    g.add_edge(0, 3, 3);
    g.add_edge(0, 4, 4);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 4, 7);
    g.add_edge(2, 3, 6);

    g.prim(0);

     return 0;
}