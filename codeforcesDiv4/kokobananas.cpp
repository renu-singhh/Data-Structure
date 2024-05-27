#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long calculateHours(const vector<int> &piles, int hourly)
{
    long long totalH = 0;
    int n = piles.size();
    for (int i = 0; i < n; ++i)
    {
        totalH += (piles[i] + hourly - 1) / hourly; // Using integer arithmetic to compute ceil(piles[i] / hourly)
    }
    return totalH;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int maxi = INT_MIN;
    for(int i=0;i<piles.size();i++){
        maxi=max(maxi,piles[i]);
    }
    int left = 1;
    int right = maxi;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        long long totalH = calculateHours(piles, mid);
        if (totalH <= h)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    int h;
    cout << "Enter the number of hours: ";
    cin >> h;
    vector<int> piles = {3, 6, 7, 11}; 
    cout << "Minimum eating speed: " << minEatingSpeed(piles, h) << endl;
    return 0;
}
