#include<algorithm>
#include<iostream>
#include<vector>

bool compare(const int x, const int y)
{
    return x < y;
}



int main()
{
    std::vector<int> a = {4, 8, 3, 1, -6, 9, 5, -9, 10, -1, 1, 2};

    std::sort(a.begin(), a.end(), compare);
    auto it = std::unique(a.begin(), a.end());
    a.resize(std::distance(a.begin(), it));

    //sada imamo strogo rastuci niz
   
    int cons_now = 0;
    int cons_best = 0;
    int best_begins, best_ends;

    for(int i = 0; i < a.size() - 1; i++)
    {
        if(a[i] + 1 == a[ i + 1])
            cons_now++;
        else if (cons_best < cons_now)
        {
            cons_best = cons_now;
            cons_now = 0;
            best_ends = i;
        }
        else
            cons_now = 0;

    }

    best_begins = best_ends - cons_best - 1;

    for (int i = best_begins; i <= best_ends; i++)
        std::cout << a[i] << " ";

    std::cout << std::endl;

    return 0;
}