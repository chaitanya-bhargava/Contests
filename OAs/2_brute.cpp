#include<bits/stdc++.h>
using namespace std;
unordered_set<int> dfs(unordered_set<int>& set1, unordered_set<int>& set2) {
    unordered_set<int> result;
    for (int num : set1) {
        if (set2.count(num) > 0) {
            result.insert(num);
        }
    }
    return result;
}
int solution(vector<int>& numbers,int N) {
    vector<unordered_set<int>> repeating(10);

    for (int number : numbers) {
        int second = number / 10;
        int first = number % 10;
        repeating[second].insert(number);
        repeating[first].insert(number);
    }
    vector<int> dp(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            int tensDigitI = numbers[i] / 10;
            int tensDigitJ = numbers[j] / 10;
            if (!repeating[tensDigitI].empty()
                    && !repeating[tensDigitJ].empty()
                    && !dfs(repeating[tensDigitI], repeating[tensDigitJ]).empty()) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < N; i++) {
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0 ; i<n ;i++)
        cin>> nums[i];
    int ans=solution(nums,n);
    cout<<ans<<endl;

}