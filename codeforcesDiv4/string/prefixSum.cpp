#include <bits/stdc++.h>
using namespace std;

// Function to fill prefix sum array
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    // Initialize the first element of prefixSum
    prefixSum[0] = arr[0];

    // Add present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}

// Driver Code
int main()
{
    int arr[] = {10, 4, 16, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];

    // Function call
    fillPrefixSum(arr, n, prefixSum);

    // Print the prefix sum array
    for (int i = 0; i < n; i++)
        cout << prefixSum[i] << " ";

    return 0;
}
