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
 
long long maxSubarraySum(vector<int> &arr) {
    long long res = arr[0];
    for(int i = 0; i < arr.size(); i++) {
        long long currSum = 0;
        for(int j = i; j < arr.size(); j++) {
            currSum = currSum + arr[j];
            res = max(res, currSum);
        }
    }
    return res;
}

long calculateMaxQualityScore(int impactFactor,vector<int> ratings){
    long long sum=0;
    for(auto x:ratings){
        sum+=x;
    }
    long long maxi=maxSubarraySum(ratings);
    long long sum2=sum+maxi*(impactFactor-1);
    for(auto x:ratings){
        x*=-1;
    }
    long long mini=maxSubarraySum(ratings);
    long long sum3=sum+mini*(impactFactor-1);
    return max(sum,max(sum2,sum3));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> ratings(n);
    for(int i=0;i<n;i++){
        cin>>ratings[i];
    }
    int impactFactor;
    cin>>impactFactor;
    int res=calculateMaxQualityScore(impactFactor,ratings);
    cout<<res<<endl;
    return 0;
}