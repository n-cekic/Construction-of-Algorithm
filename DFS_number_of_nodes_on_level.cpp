#include <iostream>
#include <queue>
#include <vector>

class Graph
{
private:
    int v;
    std::vector<int> visited;
    std::vector<std::vector<int>> adjacency_list;
    int nodes_at_level;
public:

    Graph(int v)
    {
        this->v = v;

        visited.resize(v);
        std::fill(visited.begin(), visited.end(), false);

        adjacency_list.resize(v);

        nodes_at_level = 0;
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
    }

    void DFS(int root, int level, int current_level)
    {
        visited[root] = true;

        if (current_level == level)
            nodes_at_level++;
    
        for (auto node : adjacency_list[root])
            if (!visited[node])
                DFS(node, level, current_level + 1);

        return ;   
    }

    int get_num_of_nodes()
    {
        return nodes_at_level;
    }

};

int main()
{
    Graph g(8);

    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(0, 7);
    g.add_edge(4, 6);
    g.add_edge(4, 5);
    g.add_edge(4, 2);
    g.add_edge(7, 3);

    int level;

    std::cin >> level;

    g.DFS(0, level, 0);

    std::cout << g.get_num_of_nodes() << std::endl;

    return 0;
}