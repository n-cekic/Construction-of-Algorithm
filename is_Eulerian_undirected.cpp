#include <iostream>
#include <vector>
#include <algorithm>

// Klasa kojom cemo predstavljati graf
class Graph
{
private:
    int V;
    std::vector<std::vector<int>> adjacency_list;
    std::vector<int> visited;
    std::vector<int> degrees;
public:
  // Konstruktor za graf koji samo prima broj cvorova grafa
  Graph(int V)
  {
    // Broj cvorova grafa je jednak prosledjenom argumentu
    this->V = V;
    // Alociramo mesto za V bool vrednosti koje ce cuvati posecene cvorove
    visited.resize(V);
    // Na pocetku nijedan cvor nije posecen
    /********* C++ deo *********/
    // Funkcija std::fill() prima iterator na pocetak kolekcije i kraj kolekcije i vrednost kojom treba popuniti celu kolekciju
    std:fill(visited.begin(), visited.end(), false);

    // Alociramo memoriju za V vectora, jer znamo da ce ih biti V, a svaki od njih cemo povecavati za po jedan element pomocu vector.push_back()
    adjacency_list.resize(V);

    // Alociramo prostor
    degrees.resize(V);

    // Postavljamo stepene na 0
    std::fill(degrees.begin(), degrees.end(), 0);
  }

  // Funkcija koja dodaje grane u -> v i v - > u u graf
  void add_edge(int u, int v)
  {
    // Sused cvora u je cvor v
    adjacency_list[u].push_back(v);

    // Sused cvora u je cvor v
    adjacency_list[v].push_back(u);

    // Povecavamo ulazni, odnosno izlazni stepen za oba cvora
    degrees[u]++;
    degrees[v]++;
  }

  void DFS(int u)
  {
      visited[u] = true;

      for (auto n : adjacency_list[u])
      {
          if(!visited[n])
            DFS(n);
      }
  }

  bool is_connected()
  {
      int start_node = -1;

      for(int i = 0; i < V; i++)
      {
          if(adjacency_list[i].size() > 0)
            start_node = i;
      }

      DFS(start_node);

      for (int i = 0; i < V; i++)
      {
          if (visited[i] == false)
            return false;
      }

      return true;
  }

    int is_eulerian()
    {
        int count_odd = num_of_odd_vertices();

        if (count_odd > 2)
            return 0;

        if(!is_connected())
            return 0;
        
        return count_odd == 0 ? 2 : 1;

    }

    int num_of_odd_vertices()
    {
        int result = 0;

        for (int i = 0; i < V; i++)
        {
            if (degrees[i] % 2)
                result++;
        }
        
        return result;
    }

};


int main ()
{
  Graph g(5);

  // Ciklus
  // g.add_edge(0, 1);
  // g.add_edge(1, 2);
  // g.add_edge(2, 0);

  // Nije Ojlerov
  // g.add_edge(0, 1);
  // g.add_edge(1, 2);
  // g.add_edge(1, 4);
  // g.add_edge(2, 3);

  // Put
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(0, 3);
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 3);
  g.add_edge(2, 4);
  g.add_edge(3, 4);

  int eulerian = g.is_eulerian();

  std::cout << (eulerian == 0 ? "G is not Eulerian!" 
    : (eulerian == 1 ? "G has Euler path!" : "G has Euler cycle!")) << std::endl;

  return 0;
}
