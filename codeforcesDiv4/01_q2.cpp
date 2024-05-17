/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// const int MAX = 200'007;
// const int MOD = 1'000'000'007;

void solve()
{
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 1; i < (int)(s.length()); i++)
    {
        if (s[i] != s[0])
        {
            swap(s[i], s[0]);
            ok = true;
            break;
        }
        if (!ok)
        {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        cout << s << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
