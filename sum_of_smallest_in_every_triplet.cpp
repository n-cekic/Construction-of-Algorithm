#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> a = {5,3,7,1,3,4};

    std::sort(a.begin(), a.end());

    int sum = 0;
    int size = sizeof(a) / 4;
    for (int i = 0; i < size; i ++)
    {
        int num_of_triplets = (size - i - 1) * (size - i - 2) / 2;
        
        sum += a[i] * num_of_triplets;
    }

    std::cout << sum << std::endl;
    return 0;
}