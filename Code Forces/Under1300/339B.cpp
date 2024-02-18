#include <iostream>
using namespace std;

int main()
{
    int n, m, a, x = 1;
    long long int y = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a;

        if (a > x)
            y += a - x;
        else if (a < x)
            y += (a + n) - x;
        x = a;
    }

    cout << y;
}