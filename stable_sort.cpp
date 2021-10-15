#include <iostream>
#include <vector>

class contestant
{
public:
    std::string name_surname;
    int score;

    contestant(){}

    contestant(std::string n_s, int scr)
    {
        name_surname = n_s;
        score = scr;
    }
    //~contestant();

    /*int compare(contestant b)
    {
        if(this->compare(b) < 0)
            return -1;
        else if(this->compare(b) == 0)
            return this->score - b.score;
        else
            return 0;
    }
*/
    std::string to_string()
    {
        std::string result = name_surname;
        result.append(" " + std::to_string(score));

        return result;
    }


};

void merge_sort(std::vector<contestant> &a, int left, int right)
{
    if(left >= right)
        return ;
    
    static std::vector<contestant> b(a.size());
    int mid = (left + right) / 2;

    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (a[i].name_surname.compare(a[j].name_surname) < 0)
        {
            b[k] = a[i];
            i++;
        }
        else if (a[i].name_surname.compare(a[j].name_surname) == 0)
        {
            if (a[i].score < a[j].score)
            {
                b[k] = a[i];
                i++;
            }
            else
            {
                b[k] = a[j];
                j++;
            }
        }

        else 
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    k = 0;
    i = left;
    while(i <= right)
    {
        a[i] = b[k];
        i++; 
        k++;
    }
}

int main ()
{

    contestant c1("milos jovic", 33);
    contestant c2("mile kitic", 23);
    contestant c3("ivan ivanovic", 34);
    contestant c4("ivan ivanovic", 23);
    contestant c7("ivan ivanovic", 27);
    contestant c8("ivan ivanovic", 22);
    contestant c9("ivan ivanovic", 12);
    contestant c5("marko kraljevic", 33);
    contestant c6("pera detlic", 55);

    std::vector<contestant> contestants;

    contestants.push_back(c1);
    contestants.push_back(c2);
    contestants.push_back(c3);
    contestants.push_back(c4);
    contestants.push_back(c5);
    contestants.push_back(c6);    
    contestants.push_back(c7);    
    contestants.push_back(c8);    
    contestants.push_back(c9);    

    //std::cout << contestants.size() << std::endl;

    merge_sort(contestants, 0, contestants.size() - 1);

    for(auto c : contestants)
        std::cout << c.to_string() << "\n";
    std::cout << std::endl;

    return 0;
}