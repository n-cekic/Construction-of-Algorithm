#include <iostream>
#include <vector>

void merge_sort(std::vector<int> &a, int l, int r, int &inversions)
{
    if(l >= r)
        return ;

    static std::vector<int> b(a.size());

    int m = (l + r) / 2;

    merge_sort(a, l, m, inversions);
    merge_sort(a, m + 1, r, inversions);

    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
            inversions += m - i + 1;
        }
        k++;
    }

    while (j <= r)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    while (i <= m)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    i = l;
    k = 0;
    while(i  <= r)
    {
        a[i] = b[k];
        i++;
        k++;
    }    
}

int main()
{

    std::vector<int> a = {3,2,7,4,8,4,7,4,1,6,9,5};

    int inversions = 0;

    merge_sort(a, 0, a.size() - 1, inversions);

    std::cout << inversions << "\n";
    for(auto x : a)
        std::cout << x << " ";
  
    std::cout << "\n";
  
    return 0;
}