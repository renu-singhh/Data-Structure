#include <bits/stdc++.h>
using namespace std;

long long getwood(vector<long long> &trees, int height)
{
    long long res = 0;
    for (auto h : trees)
    {
        long long wood = h - height;
        if (wood >= 0)
            res += wood;
    }
    return res;
}

// n * log (max height of tree)

int main()
{
    int n, x;
    long long k, mx = -1;
    cin >> n >> k;
    vector<long long> trees(n);
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
        mx = max(mx, trees[i]);
    }
    int left = 0, right = mx, mid, ans;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        long long wood = getwood(trees, mid);
        if (wood >= k)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans;
}