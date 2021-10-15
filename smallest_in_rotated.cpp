#include <iostream>
#include <vector>

int smallest(std::vector<int> &a)
{
    int l = 0, r = a.size() - 1, m;

    while (l <= r)
    {
        m = (r + l) / 2;
        if (a[m - 1] > a[m] && a[m + 1] > a[m])
            return m;
        if(a[m] > a[0])
            l = m + 1;
        else
            r = m - 1;
    }

    return l < a.size() ? l : 0;
}


int main()
{
    std::vector<int> a = {4, 5, 1, 2, 3};

    std::cout << smallest(a) << std::endl;

    return 0;
}