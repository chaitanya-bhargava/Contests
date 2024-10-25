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
 

int helper(string & s,vector<int> & pre,int i,int ind,vector<vector<unordered_map<string,int>>> & dp){
    if(i==s.size()){
        if(ind==s.size()+1) return 0;
        else return INT_MIN;
    }
    int ans1=0;
    int ans2=0;
    if(dp[i][ind]!=-1) return dp[i][ind];
    if(ind==s.size()+1){
        if(s[i]=='L') ans1+=helper(s,pre,i+1,i,dp);
        ans2+=helper(s,pre,i+1,ind,dp);
    }
    else{
        if(s[i]=='R'){
            s[i]='.';
            s[ind]='.';
            ans1+=pre[i+1]-pre[ind]+helper(s,pre,0,s.size()+1,dp);
            s[i]='R';
            s[ind]='L';
        }
        ans2+=helper(s,pre,i+1,ind,dp);
    }
    // cout<<i<<" "<<ind<<endl;
    // cout<<s<<endl;
    // cout<<ans1<<" "<<ans2<<endl;
    return dp[i][ind]=max(ans1,ans2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> pre(n+1);
        pre[0]=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            pre[i+1]=pre[i]+a[i];
        }
        string s;
        cin>>s;
        int m=s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+2,-1));
        cout<<helper(s,pre,0,n+1,dp)<<endl;
    }
    return 0;
}