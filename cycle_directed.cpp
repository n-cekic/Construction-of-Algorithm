#include <iostream>
#include <vector>

class Graph
{
private:
  // Lista susedstva. Imamo vector vector-a, sto znaci za svaki od cvorova [0,V) imamo po jednu listu koja cuva susede odgovarajuceg cvora
  std::vector<std::vector<int>> adjacency_list;
  // Broj cvorova grafa
  int V;
  // Lista posecenih cvorova. Da ne bismo ulazili u beskonacnu rekurziju ne zelimo da obilazimo cvorove koje smo vec obisli na putu kojim smo krenuli, zato cuvamo listu
  // posecenih cvorova
  std::vector<bool> visited;

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
  }

  // Funkcija koja dodaje granu u -> v u graf
  void add_edge(int u, int v)
  {
    // Sused cvora u je cvor v
    adjacency_list[u].push_back(v);
  }

    bool DFS(int u)
    {
        visited[u] = true;

        for (auto node : adjacency_list[u])
        {
            if (visited[node])
                return true;
            else if (DFS(node))
                return true;
        }

        visited[u] = false;

        return false;


    }





};

int main ()
{
    // Graph g(4);

    // g.add_edge(0, 1);
    // g.add_edge(0, 2);
    // g.add_edge(1, 2);
    // g.add_edge(2, 0);
    // g.add_edge(2, 3);
    // g.add_edge(3, 3);

    Graph g(2);

    g.add_edge(0, 1);

    // Graph g(3);
    // g.add_edge(0, 1);
    // g.add_edge(1, 2);
    // g.add_edge(0, 2);

    std::cout << g.DFS(0) << std::endl;

    return 0;
}
