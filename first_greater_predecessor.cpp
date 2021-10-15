#include <vector>
#include <stack>
#include <iostream>


int main()
{
    std::stack<int> stack;
    
    int n;
    std::cin >> n;


    std::vector<int> input(n);

    for(int i = 0; i < n; i++)
    {
        std::cin >> input[i];
    }


    for(int i = 0; i < n; i++)
    {
        while(!stack.empty() && stack.top() < input[i])
        {
            stack.pop();
        }

        if(stack.empty())
            std::cout << "- ";
        else
            std::cout << stack.top() << " ";

        stack.push(input[i]);
    }



    return 0;
}