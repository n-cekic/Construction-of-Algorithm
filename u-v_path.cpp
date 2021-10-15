#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


class Graph
{
private:

    int v;
    std::vector<bool> visited;
    std::vector<std::vector<int>> adjacency_list;
    bool path_found = false;

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

    void find_path(int start, int end, std::vector<int> &result)
    {
        // ako je put pronadjen samo se vracamo
        if(path_found)
            return ;

        // ako smo dosli do kraj dodamo ga i vracamo se
        if(start == end)
        {
            result.push_back(end);
            path_found = true;
            return ;
        }

        // ako smo posetili sve susede, a nismo dosli do kraja
        // ili nismo dosli do kraja, a dalje no mozemo
        // vracamo se
        if(all_nbs_visited(start) || adjacency_list[start].empty())
            return ;

       
        result.push_back(start);

        visited[start] = true;

        for (auto node : adjacency_list[start])
            find_path(node, end, result);
        

        auto tmp = std::find(result.begin(), result.end(), end);

        if(tmp == result.end())
            result.resize(0);

        return ;
    }

    bool all_nbs_visited( int node)
    {
        bool result = true;
        for (auto x : adjacency_list[node])
            result = result && visited[x];

        return result;
    }

};


int main()
{
    int u, v;
    std::cin >> u;
    std::cin >> v;
    
    Graph g(6);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 1);
    g.add_edge(4, 3);
    g.add_edge(3, 4);
    g.add_edge(3, 5);

    std::vector<int> path;

    g.find_path(u, v, path);

    if (!path.empty())
    {
        for(auto n : path)
            std::cout << n << " ";
        std::cout << std::endl;
    }
    else
        std::cout << "Path not found!" << "\n";

    return 0;
}