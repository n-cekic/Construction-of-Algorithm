#include <iostream>
#include <queue>
#include <vector>

struct compare
{
    compare() {}
    
    bool operator()(int x, int y)
    {
        return x < y;
    }
};



int main()
{
    std::priority_queue<int, std::vector<int>, std::less<int>> heap;

    std::vector<int> a = {3,2,1,5,7,4,6};

    for(auto x : a)
        heap.push(x);

    for(int i = a.size() -1; i >= 0; i--)
    {
        a[i] = heap.top();
        heap.pop();
    }

    for (int x : a)
        std::cout << x << " ";
    std::cout << "\n";


    return 0;
}