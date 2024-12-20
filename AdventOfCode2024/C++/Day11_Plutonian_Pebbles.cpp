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
 
const int n=8;
const int m=75;

void blink(vector<ll> & stones){
    int sz=stones.size();
    for(int i=0;i<sz;i++){
        if(stones[i]==0) stones[i]=1;
        else if(to_string(stones[i]).size()%2==0){
            string num_s=to_string(stones[i]);
            int sz=num_s.size();
            stones[i]=stoll(num_s.substr(0,sz/2));
            stones.push_back(stoll(num_s.substr(sz/2,sz/2)));
        }
        else{
            stones[i]*=2024;
        }
    }
}

void blink2(unordered_map<ll,ll> & stones){
    unordered_map<ll,ll> stones2;
    for(auto it:stones){
        if(it.first==0){
            stones2[1]+=stones[0];
        }
        else if(to_string(it.first).size()%2==0){
            string num_s=to_string(it.first);
            int sz=num_s.size();
            stones2[stoll(num_s.substr(0,sz/2))]+=it.second;
            stones2[stoll(num_s.substr(sz/2,sz/2))]+=it.second;
        }
        else{
            stones2[it.first*2024]+=it.second;
        }
    }
    stones=stones2;
}

// A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<ll> stones(n);
//     for(int i=0;i<n;i++){
//         cin>>stones[i];
//     }
//     for(int i=0;i<m;i++){
//         blink(stones);
//         // for(auto x:stones){
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;
//     }
//     cout<<stones.size()<<endl;
//     return 0;
// }

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<ll,ll> mp;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        mp[k]++;
    }
    for(int i=0;i<m;i++){
        blink2(mp);
        // for(auto x:stones){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
    }
    ll res=0;
    for(auto it:mp){
        res+=it.second;
    }
    cout<<res<<endl;
    return 0;
}