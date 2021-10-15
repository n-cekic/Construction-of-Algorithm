#include <iostream>
#include <cstdlib>
#include <climits>

#define INFINITY 9999

// Klasa kojom cemo predstavljati graf
class Graph
{
private:
    int V;
    int **matrix;
public:
  // Konstruktor za graf koji samo prima broj cvorova grafa
  Graph(int V)
  {
    // Broj cvorova grafa je jednak prosledjenom argumentu
    this->V = V;
    // Alociramo mesto za V bool vrednosti koje ce cuvati posecene cvorove

    // Alociramo prostor za niz nizova, tj matricu, u C++-u moramo da imamo eksplicitno kastovanje u (int **), odsnosno (int *) inace se g++ buni
    matrix = (int **)malloc(V * sizeof(int *));
    // Svaki od elemenata matrice je novi niz, pa se alocira
    // i memorija za njih
    for (int i = 0; i < V; i++)
      matrix[i] = (int *)calloc(sizeof(int), V);

    // Kazemo da je svaki element matrice matrix jednak INFINITY osim elemenata na dijagonali koji su 0
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++) {
        if (i == j)
          matrix[i][j] = 0;
        else
          matrix[i][j] = INFINITY;
      }
  }

  // Dodajemo granu izmedju u i v koja je tezine weight
  void add_edge(int u, int v, int weight)
  {
    matrix[u][v] = weight;
  }

    void floyd_warshall()
    {
     for (int mid = 0; mid < V; mid++)
     {
         for (int start = 0; start < V; start++)
         {
             for (int end = 0; end < V; end++)
             {
                 if (matrix[start][end] > matrix[start][mid] + matrix[mid][end])
                    matrix[start][end] = matrix[start][mid] + matrix[mid][end];
             }
         }
     } 

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if(matrix[i][j] < 0)
                {
                    std::cout << "YES!" << "\n";
                    return;
                }
            }
        }
        std::cout << "NO!" << "\n";
    }

};

int main ()
{
    Graph g(4);

    g.add_edge(0, 1, 1);
    g.add_edge(1, 2, -1);
    g.add_edge(2, 3, -1);
    g.add_edge(3, 0, -1);

    g.floyd_warshall();

    return 0;
}