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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        map<ll,ll> mp;
        for(ll i=0;i<n;i++){
            ll num;
            cin>>num;
            mp[num]++;
        }
        for(auto x:mp){
            if(mp.find(x.first-k+1)==mp.end()){
                mp[x.first-k+1]=0;
            }
        }
        vector<pair<ll,ll>> pre;
        for(auto x:mp){
            pre.push_back({x.first,x.second});
        }
        for(ll i=1;i<pre.size();i++){
            pre[i].second+=pre[i-1].second;
        }
        // for(ll i=0;i<pre.size();i++){
        //     cout<<pre[i].first<<" "<<pre[i].second<<endl;
        // }
        ll ans=pre[0].second;
        for(ll i=1;i<pre.size();i++){
            ans=max(ans,pre[i].second-pre[i-k].second);
        }
        cout<<ans<<endl;
    }
    return 0;
}