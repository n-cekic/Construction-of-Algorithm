#include<iostream>
#include<vector>

std::vector<int> prefix(const std::string &s)
{
    std::vector<char> pattern(s.begin(), s.end());
    int n = pattern.size();
    std::vector<int> prefix_table(n);

    prefix_table[0] = 0;
    int i = 1, j = 0;

    while (i < n)
    {
        if (pattern[i] == pattern[j])
        {
            prefix_table[i] = j + 1;
            i++; j++;
        }
        else if (j != 0)
        {
            j = prefix_table[j - 1];
        }
        else
        {
            prefix_table[i] = 0;
            i++;
        }
    }
    
    return prefix_table;
}


std::vector<int> compute_prefix(const std::string &p)
{
    std::vector<char> pattern(p.begin(), p.end());
    int n = p.size();
    std::vector<int> table(n);
    
    table[0] = 0;
    int j = 0, i = 1;
    while (i < n)
    {
        if (pattern[i] = pattern[j])
        {
            table[i] = j + 1;
            i++; j++;
        }

        else if (j > 0)
            j = table[j - 1];
        
        else
        {
            table[i] = 0;
            i++;
        }
            
    }
    return table;
}

int kmp(const std::string &pattern, const std::string &text)
{
    std::vector<int> prefix_table = compute_prefix(pattern);

    int i = 0, m = text.size();
    int j = 0, n = pattern.size();

    while (i < m)
    {
        if (pattern[j] == text[i])
        {
            i++; j++;
        }

        if (j == n)
            return i - j;
        
        if (pattern[j] != text[i])
        {
            if ( j > 0)
               j = prefix_table[j - 1];
            else
                i++;
        }
    }
    return -1;
}


int main()
{
    std::string text = "aabxaabaxaababc";

    std::string pattern = "aababc";

    int index = kmp(pattern, text);

    std::cout << index << std::endl;

    return 0;
}