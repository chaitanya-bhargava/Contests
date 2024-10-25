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
 
#include <vector>

std::vector<int> solution(std::vector<int> numbers) {
    std::vector<int> first, second;
    
    // Step 1: Distribute numbers[0] and numbers[1]
    first.push_back(numbers[0]);
    second.push_back(numbers[1]);
    
    // Step 2: Distribute remaining numbers
    for (int i = 2; i < numbers.size(); i++) {
        int num = numbers[i];
        int greater_first = 0, greater_second = 0;
        
        // Count elements greater than num in first and second arrays
        for (int j : first) {
            if (j > num) greater_first++;
        }
        for (int j : second) {
            if (j > num) greater_second++;
        }
        
        // Decide which array to append num based on the rules
        if (greater_first > greater_second) {
            second.push_back(num);
        } else if (greater_first < greater_second) {
            first.push_back(num);
        } else {
            // Tie case: append to the array with lower length
            if (first.size() <= second.size()) {
                first.push_back(num);
            } else {
                second.push_back(num);
            }
        }
    }
    
    // Step 3: Combine first and second arrays
    first.insert(first.end(), second.begin(), second.end());
    
    return first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    vector<int> ans=solution(numbers);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}