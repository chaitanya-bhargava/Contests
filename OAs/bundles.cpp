#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define V vector
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define eb emplace_back
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define fi first
#define se second
#define _F(i, a, b) for (int i = a; i <= b; i++)
#define _FR(i, a, b) for (int i = a; i >= b; i--)
#define IF(a,b,c) ((a)?(b):(c));
#define _sort(x) sort((x).begin(),(x).end());
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const ll infl = 0x3f3f3f3f3f3f3f3fll;
 

int maxBooks(int budget,vector<int>& bundleQuantities,vector<int>& bundleCosts) {
    int n = bundleQuantities.size();
    vector<int> dp(budget + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = bundleCosts[i]; j <= budget; ++j) {
            dp[j] = max(dp[j], dp[j - bundleCosts[i]] + bundleQuantities[i]);
        }
    }

    return dp[budget];
}

int main() {
    int budget;
    cout<<"auiufbwuf"<<endl;
    vector<int> bundleQuantities = {20, 19}; // Example bundle quantities
    vector<int> bundleCosts = {24,20};     // Example bundle costs

    cout << "Enter your budget: ";
    cin >> budget;

    int maxBooksCount = maxBooks(budget, bundleQuantities, bundleCosts);
    cout << "Maximum number of books you can buy: " << maxBooksCount << endl;

    return 0;
}
