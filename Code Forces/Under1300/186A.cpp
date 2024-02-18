#include <iostream>
using namespace std;

int main()
{
    string g1, g2;
    cin >> g1 >> g2;

    int j = -1, k = -1;
    bool flag = true;

    for (int i = 0; i < g1.length(); i++)
    {
        if (g1[i] != g2[i])
        {
            if (j == -1)
            {
                j = i;
            }

            else if (k == -1)
            {
                k = i;

                if (g1[j] != g2[k] || g2[j] != g1[k])
                {
                    flag = false;
                    break;
                }
            }

            else
            {
                flag = false;
                break;
            }
        }
    }

    if (j != -1 && k == -1)
        flag = false;

    cout << (flag ? "YES" : "NO");
}