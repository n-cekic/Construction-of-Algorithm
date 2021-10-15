#include <iostream>
#include <vector>
#include <algorithm>


class Graph
{
    int V;
    std::vector<int> degrees;
    std::vector<bool> visited;
    std::vector<std::vector<int>> adjacency_list;

public:

    Graph(int V)
    {
        this->V = V;

        degrees.resize(V);
        std::fill(degrees.begin(), degrees.end(), 0);

        visited.resize(V);
        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(V);
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);

        degrees[u]++;
        degrees[v]++;
    }

    void DFS(int u)
    {
        visited[u] = true;

        for (auto node : adjacency_list[u])
        {
            // proveravamo da li smo vec posetili i da li je grana obrisana
            if (node != -1 && !visited[node])
                DFS(node);
        }
    }

    int num_of_odd_verticies()
    {
        int res = 0;

        for (int i = 0; i < V; i++)
        {
            if (degrees[i] % 2)
                res++;
        }

        return res;
    }

    int find_node_with_odd_degree()
    {
        for (int i = 0; i < V; i++)
        {
            if (degrees[i] % 2)
                return i;
        }
        return -1;
    }

    int find_node_with_even_degree()
    {
        for (int i = 0; i < V; i++)
        {
            if (degrees[i] % 2 == 0 && degrees[i])
                return i;
        }
        return -1;
    }
    
    void fleury()
    {
        int count_odd = num_of_odd_verticies();

        int start_node;

        if (count_odd == 0)
        {
            start_node = find_node_with_even_degree();
            print_eulerian(start_node);
        }

        else if (count_odd == 2)
        {
            start_node = find_node_with_odd_degree();
            print_eulerian(start_node);
        }
    }

    void print_eulerian(int u)
    {
        for (auto v : adjacency_list[u])
        {
            if (v != -1 && is_valid_edge(u, v))
            {
                std::cout << u << "->" << v << "\n";
                remove_edge(u, v);
                print_eulerian(v);
            }
        }
    }

    bool is_valid_edge(int u, int v)
    {
        int count_edges = std::count_if(adjacency_list[u].begin(), adjacency_list[u].end(), [](int x){return x != -1;});

        if (count_edges == 1)
            return true;

        remove_edge(u, v);

        std::fill(visited.begin(), visited.end(), false);

        DFS(u);

        adjacency_list[u].erase(std::find(adjacency_list[u].begin(), adjacency_list[u].end(), -1));

        adjacency_list[v].erase(std::find(adjacency_list[v].begin(), adjacency_list[v].end(), -1));

        add_edge(u, v);

        if (!visited[v])
            return false;

        return true;
    }

    void remove_edge(int u, int v)
    {
        auto it_u = std::find(adjacency_list[u].begin(), adjacency_list[u].end(), v);
        *it_u = -1;

        auto it_v = std::find(adjacency_list[v].begin(), adjacency_list[v].end(), u);
        *it_v = -1;
    }
};


int main ()
{
    Graph g(5);

    // Put
    // g.add_edge(0, 1);
    // g.add_edge(0, 2);
    // g.add_edge(1, 2);
    // g.add_edge(2, 3);

    // Ciklus
    // g.add_edge(0, 1);
    // g.add_edge(1, 2);
    // g.add_edge(2, 0);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    g.fleury();

    return 0;
}
