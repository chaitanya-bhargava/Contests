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
 
map<vector<long long>, long long> memo;

long long helper(vector<long long> & arr,unordered_map<long long,bool> & mp,long long i,long long lcm,long long ans){
    if(i==arr.size()){
        if(mp[lcm]) return INT_MIN;
        return ans;
    } 
    vector<long long> key;
    key.push_back(i);
    key.push_back(lcm);
    key.push_back(ans);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    long long not_pick=helper(arr,mp,i+1,lcm,ans);
    long long pick=helper(arr,mp,i+1,lcm*arr[i]/__gcd(lcm,arr[i]),ans+1);
    return memo[key]=max(pick,not_pick);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        unordered_map<long long,bool> mp;
        for(long long i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]=true;
        }
        long long ans=helper(arr,mp,0,1,0);
        memo.clear();
        if(ans==INT_MIN) cout<<0<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}