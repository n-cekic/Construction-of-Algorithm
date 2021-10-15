#include<iostream>
#include<stack>
#include<string>

int main()
{
    std::stack<char> stack;
    std::string input_string;

    std::cin >> input_string;

    for (auto c : input_string) {
        if (c == '(' || c == '{' || c == '[')
            stack.push(c);

        if ((c == ')' || c == '}' || c == ']') && stack.empty())
        { 
            std::cout << "Not matched";
            return 0;
        }

        else if (c == ')' && stack.top() == '(' ) {
            if (stack.empty()) {
                std::cout << "Not matched, bad order\n";
                return 0;
            }
            stack.pop();
        }
        else if (c == ']' && stack.top() == '[' ) {
            if (stack.empty()) {
                std::cout << "Not matched, bad order\n";
                return 0;
            }
            stack.pop();
        }
        else if (c == '}' && stack.top() == '{' ) {
            if (stack.empty()) {
                std::cout << "Not matched, bad order\n";
                return 0;
            }
            stack.pop();
        }
        
    }

    std::cout << (stack.empty() ? "Matched" : "Not matched") << "\n";


    return 0;
}