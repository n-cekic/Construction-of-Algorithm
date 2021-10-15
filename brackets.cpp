#include <iostream>
#include <stack>
#include <string>

int main()
{

    std::stack<char> stack;
    std::string expression;

    std::cin >> expression;

    for(char c : expression) {
        if (c == '(' )
            stack.push(c);
        else if (c == ')'){
            if(stack.empty()) {
                std::cout << "Fatal error, kill yourself\n";
                return 0 ;
            }
            stack.pop();
        }
        else
        {
            std::cout << "what is this?\n";
            continue;
        }
    }

    std::cout << (stack.empty() ? "Matched!" : "Not matched :(...");
    std::cout << "\n";

    return 0;
}