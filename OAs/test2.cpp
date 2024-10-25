#include <bits/stdc++.h>
using namespace std;
#define int long long
int d(int index, int n, vector<int> &arr, int prev, vector<vector<int>> &dp)
{
    if (index >= n)
        return 0;
    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];
    int take = 0, nottake = 0;
    if (prev == -1 || arr[prev] > arr[index])
        take = arr[index] + d(index + 1, n, arr, index, dp);
    nottake = 0 + d(index + 1, n, arr, prev, dp);
    return dp[index][prev + 1] = max(take, nottake);
}
int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = d(0, n, arr, -1, dp);
    cout << ans;
    return 0;
}