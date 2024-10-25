#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; i++)
        {
            indexMap[arr[i]] = i;
        }

        for (int i = 0; i < n && k > 0; i++)
        {
            if (arr[i] != n - i)
            {
                int targetValue = n - i;
                if (indexMap.find(targetValue) != indexMap.end())
                {
                    int targetIndex = indexMap[targetValue];
                    if (abs(targetIndex - i) >= k)
                    {
                        swap(arr[i], arr[targetIndex]);
                        indexMap[arr[i]] = i;
                        indexMap[arr[targetIndex]] = targetIndex;
                        k--;
                    }
                }
            }
        }
        for (long long i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}