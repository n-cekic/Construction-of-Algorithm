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

int binary_search(std::vector<int> &a, int rotation, int x)
{
    if (a[rotation - 1] < x)
        return -1;
    else if (x > a.back())
    {
        int left = 0;
        int right = rotation;
        //int mid = (left + right) / 2;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (a[mid] < x)
                left = mid;
            else if (a[mid] > x)
                right = mid;
            else
                return mid;
        }
    }
    else
    {
        int left = rotation;
        int right = a.size();
        //int mid = (left + right) / 2;
        //pretrazi u rotation do end
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (a[mid] < x)
                left = mid;
            else if (a[mid] > x)
                right = mid;
            else
                return mid;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> a = {4, 5, 1, 2, 3};

    int rotation = smallest(a);

    int x = 7;

    int index = binary_search(a, rotation, x);

    std::cout << (index >= 0 ? std::to_string(index)  : "Not found") << std::endl;

    return 0;
}