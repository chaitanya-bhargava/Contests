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
 
//A
ll helper(string & match,unordered_map<string,bool> & mp,ll i,vector<ll> & dp){
    if(i==match.size()) return 1;
    if(dp[i]!=-1) return dp[i];
    for(ll j=1;j+i<=match.size();j++){
        if(mp[match.substr(i,j)]){
            if(helper(match,mp,i+j,dp)) return dp[i]=1;
        }
    }
    return dp[i]=0;
}

//B
ll helper2(string & match,unordered_map<string,bool> & mp,ll i,vector<ll> & dp){
    if(i==match.size()) return 1;
    if(dp[i]!=-1) return dp[i];
    ll ans=0;
    for(ll j=1;j+i<=match.size();j++){
        if(mp[match.substr(i,j)]){
            ans+=helper2(match,mp,i+j,dp);
        }
    }
    return dp[i]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> lines;
    fstream ss("input.txt");
    ofstream sso("output.txt");
    string line;
    while(getline(ss,line)){
        lines.push_back(line);
    }
    unordered_map<string,bool> mp;
    lines[0]=" "+lines[0];
    stringstream ss2(lines[0]);
    string p;
    while(getline(ss2,p,',')){
        p.erase(0,1);
        sso<<p<<endl;
        mp[p]=true;
    }
    ll res=0;
    sso<<endl;
    for(ll i=2;i<lines.size();i++){
        string match=lines[i];
        sso<<match<<endl;
        vector<ll> dp(match.size()+2,-1);
        res+=helper2(match,mp,0,dp);
    }
    cout<<res<<endl;
    return 0;
}