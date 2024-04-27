#include <map>
#include <iostream>
using namespace std;

int count_divisor(int n)
{
    int cnt = 2;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            cnt++;
    }
    return cnt;
}

int main()
{
    int a, b, c, sum = 0;
    cin >> a >> b >> c;
    int m = 1073741824;

    map<int, int> div_map;
    div_map[1] = 1;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                int v = i * j * k;
                if (div_map[v] == 0)
                    div_map[v] = count_divisor(v);
                sum += div_map[v];
            }
        }
    }

    cout << sum % m << endl;
}