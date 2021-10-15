#include <iostream>
#include <vector>

void swap(std::vector<int> &a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j]; 
    a[j] = temp; 
}

int partition(std::vector<int> &a, int left, int right)
{
    int pivot = a[right];
    int i = left - 1, j;
    for (j = left; j < right; j++)
    {
        if (pivot > a[j])
        {
            i++;
            swap(a, i, j);
        }
    }

    swap(a, i+1, j);
    return i+1;
}

void quick_sort(std::vector<int> &a, int left, int right)
{

    if(right < left)
        return;

    int p = partition(a, left, right);
    quick_sort(a, left, p - 1);
    quick_sort(a, p + 1 , right);
}

int main()
{

    std::vector<int> a = {3,7,0,4,1,5,2,9,8,6};
    
    //int p = partition(a, 0, a.size());
    quick_sort(a, 0, a.size());

    for (auto x : a)
        std::cout << x << " ";

    

    return 0;
}