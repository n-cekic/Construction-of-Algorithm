#include <iostream>
#include <vector>

class Graph
{
    int V;
    std::vector<bool> visited;
    std::vector<std::vector<int>> adjacency_list;

public:

    Graph(int V)
    {
        this->V = V;

        visited.resize(V);
        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(V);
    }

    void add_edge(int u, int  v)
    {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    void set_unvisited(int u)
    {
        visited[u] = false;
    }

    void set_visited(int u)
    {
        visited[u] = true;
    }
    
    void all_paths(int u, std::vector<int> path)
    {
        visited[u] = true;

        path.push_back(u);

        if (path.size() == V)
        {
            for (auto node : path)
                std::cout << node << " ";

            std::cout << "\n";
            return ;
        }

        for (auto node : adjacency_list[u])
        {
            if (!visited[node])
             {
                all_paths(node, path);

                visited[node]=false;
             }
        }
    }
};

int main ()
{
    Graph g(3);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 0);

    std::vector<int> path;

    for (int i = 0; i < 3; i++) {
        g.all_paths(i, path);
        g.set_unvisited(i);
    }

    return 0;
}
