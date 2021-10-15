#include <iostream>

int main()
{   
    int a[] = {-3, -4, -1, 0, 4, 5, 6, 7, 4, 6, 7};

    int min = a[0];
    int max = a[0];

    int a_size = sizeof(a) / 4;
    for (int i = 0; i < a_size; i++)
    {
        if (min > a[i])
            min = a[i];
        if (max < a[i])
            max = a[i];
    }

    int range = max - min + 1;

    int b[range];
    for (int  i = 0; i < range; i++)
        b[i] = 0;
    
    for (int x : a)
        b[x-min]++;

    for (int i = 0; i < range; i ++)
    {
        if (b[i] > 0)
        {
            for(int j = 0; j < b[i]; j++)
                std::cout << i + min << " ";
        }
    }

    std::cout << "\n";


    return 0;
}