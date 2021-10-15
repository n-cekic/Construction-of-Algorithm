#include <iostream>
#include <vector>


void merge_sort(std::vector<int> &a, int left, int right)
{
    if (left >= right)
        return;
    
    int mid = (left + right) / 2;
    static std::vector<int> b(a.size());

    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);

    int k = 0, i = left, j = mid + 1;

    while (i <= mid && j <= right)
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
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    i = left;
    k = 0;
    while (i <= right) 
    {
        a[i] = b[k];
        i++;
        k++;
    }
}


int main()
{
    std::vector<int> a = {3,5,2,8,5,10,7,0,1,5,7,6,3,4,8};

    merge_sort(a, 0, a.size() - 1);

    for (auto x : a)
        std::cout << x << " ";
    
        std::cout << std::endl;

}