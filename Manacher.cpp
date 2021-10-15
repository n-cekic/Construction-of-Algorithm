#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

void manacher(const std::string &string)
{
    int n = string.size();

    std::string pom = "$";

    for (int i = 0; i < n; i++)
    {
        pom += "#";
        pom += string[i];
    }
    pom += "#@";


    int C = 1, R = 1;


    std::vector<int> pom_vector(pom.size());

    int mirror;
    n = pom.size();

    for (int i = 1; i < pom.size() - 1; i++)
    {
        mirror = 2 * C - i;
        if (i < R)
            pom_vector[i] = std::min(R - i, pom_vector[mirror]);

        //    while (pom[i + (pom_vector[i] + 1)] == pom[i - (pom_vector[i] + 1)])
        while (pom[i + (pom_vector[i] + 1)] == pom[i - (pom_vector[i] + 1)]) 
            pom_vector[i]++;

        if (i + pom_vector[i] > R)
        {
            C = i;
            R = i + pom_vector[i];
        }
    }

    int max_position = std::max_element(pom_vector.begin(), pom_vector.end()) - pom_vector.begin();
    int max = pom_vector[max_position];

    int start = max_position - max + 1;

    std::string res = "";

    int end = start + 2 * max;

    for (int i = start; i < end; i += 2)
    {
        res += pom[i];
    }

    std::cout << res << std::endl;
}


int main()
{
    std::string word = "abccba";
    manacher(word);

    return 0;
}