#include <stack>
#include <iostream>
#include <vector>

class queue
{
private:
    std::stack<int> push_stack;
    std::stack<int> pop_stack;


public:
    queue() {}

    void push(int e)
    {
        push_stack.push(e);
    }

    int pop()
    {
        if(pop_stack.empty())
        {
            while(!push_stack.empty())
            {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }

        }

        int top = pop_stack.top();
        pop_stack.pop();

        return top;
    }
};

int main ()
{
    queue q;

    q.push(1);
    q.push(2);

    std::cout << q.pop() << std::endl;

    q.push(3);  
    
    std::cout << q.pop() << std::endl;

    std::cout << q.pop() << std::endl;

    return 0;
}
