#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int mod=1e9+7;
int helper(unordered_map<int,vector<int>> &mp,vector<int> &v,int ind,int prev){
    if(ind==v.size()) return 1;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    int ans=0;
    for(auto it:mp[v[ind]]){
        if(it>prev) ans+=helper(mp,v,ind+1,it);
        ans%=mod;
    }
    return dp[ind][prev]=ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<=1000;i++){
            string s=to_string(i);
            int val=0;
            for(auto it:s){
                val+=it-'0';
            }
            mp[val].push_back(i);
        }
        memset(dp,-1,sizeof(dp));
        cout<<helper(mp,v,0,0)<<endl;
    }
    return 0;
}