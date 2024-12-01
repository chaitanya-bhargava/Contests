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
const ll infl = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
 
int helper(int i,int & n,vector<int> & red,vector<int> & dp){
    if(i==n){
        return 1;
    }
    if(i>n){
        return 0;
    }
    if(red[i]==1) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=(helper(i+1,n,red,dp)%mod+helper(i+2,n,red,dp)%mod)%mod;
}

int totalWays(int input1,int input2,int input3[]){
    vector<int> red(input1+1,0);
    for(int i=0;i<input2;i++){
        red[input3[i]]=1;
    }
    vector<int> dp(input1+1,-1);
    return helper(0,input1,red,dp)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    int ans=totalWays(n,m,arr);
    cout<<ans<<endl;
    return 0;
}