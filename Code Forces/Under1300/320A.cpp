#include <iostream>
using namespace std;

int main()
{
    string x;
    cin >> x;
    int c = 2;
    int m = 1;

    for (int i = 0; x[i]; i++)
    {
        if (x[i] == '4')
            c++;
        else if (x[i] == '1')
            c = 0;
        else
        {
            m = 0;
            break;
        }

        if (c > 2)
        {
            m = 0;
            break;
        }
    }

    if (m == 1)
        cout << "YES";
    else
        cout << "NO";
}
