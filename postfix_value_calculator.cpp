#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>


std::vector<std::string> parse_string(const std::string &expression)
{
    std::string string = expression;
    std::vector<std::string> parts;

    int position = 0;

    while ((position = string.find(" ")) != std::string::npos)
    {
        parts.push_back(string.substr(0, position));
        string.erase(0, position + 1);
    }

    parts.push_back(string.substr(0, position));

    return parts;
}

int main() 
{
    std::stack<std::string> stack;
    
    std::string input_string = "5 7 + 6 2 - *";

    std::vector<std::string> parts = parse_string(input_string);
        
    int temp1, temp2;
    for (const auto part : parts)
    {
        if (part == "+")
        {
            temp1 = std::stoi(stack.top());
            stack.pop();
            temp2 = std::stoi(stack.top());
            stack.pop();
            stack.push(std::to_string(temp1 + temp2));
        }
        else if (part == "*")
        {
         temp1 = std::stoi(stack.top());
            stack.pop();
            temp2 = std::stoi(stack.top());
            stack.pop();
            stack.push(std::to_string(temp1 * temp2));   
        }
        else if (part == "-")
        {temp1 = std::stoi(stack.top());
            stack.pop();
            temp2 = std::stoi(stack.top());
            stack.pop();
            stack.push(std::to_string(temp2 - temp1));}
        else if (part == "/")
        {
            temp1 = std::stoi(stack.top());
            stack.pop();
            temp2 = std::stoi(stack.top());
            stack.pop();
            stack.push(std::to_string(temp2 / temp1));
        }

        else
        {
            stack.push(part);
        }
        
    }

    std::cout << stack.top() << std::endl;

    return 0;
}