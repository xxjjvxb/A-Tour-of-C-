#include <iostream>
#include <vector>

using namespace std;



void increment()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for (auto& x:v) {
        cout << &x << x << " " << sizeof(x) << endl;
        ++x;
        cout << &x << x << " " << sizeof(x) << endl;
    }

    for (auto x:v)
        cout << x << " ";

    cout << endl << endl;
}

int count_b(char *p, char x)
{
    int count = 0;

    while(p)
    {
        if(*p == x)
        {
            ++count;
            cout << *p;
        }
        ++p;
        cout << p;
        if( count == 0) break;
    }

    return count;
}

int main()
{
    char *test = "asdfasdfasdf";
    increment();

    cout << count_b(test,'a');
}
