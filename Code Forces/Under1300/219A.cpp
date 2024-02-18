#include <iostream>
using namespace std;

int main()
{
    int k;
    string s;
    int f = 1;
    cin >> k >> s;
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++)
        arr[s[i] - 97]++;

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % k != 0)
        {
            f = 0;
            break;
        }
    }

    if (f == 0)
        cout << -1;

    else
    {
        string sub = "";
        string output = "";

        for (int i = 0; i < 26; i++)
        {
            int occ = arr[i] / k;
            for (int j = 0; j < occ; j++)
                sub += (char)(i + 97);
        }

        for (int i = 0; i < k; i++)
            output += sub;

        cout << output;
    }
}
