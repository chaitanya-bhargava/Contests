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
 
// A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> lines;
//     fstream ss("input.txt");
//     ofstream sso("output.txt");
//     string line;
//     while(getline(ss,line)){
//         lines.push_back(line);
//     }
//     ll final=0;
//     for(auto x:lines){
//         ll sec=stoll(x);
//         for(int i=0;i<2000;i++){
//             ll res=sec*64;
//             sec^=res;
//             sec%=16777216;
//             res=sec/32;
//             sec^=res;
//             sec%=16777216;
//             res=sec*2048;
//             sec^=res;
//             sec%=16777216;
//         }
//         final+=sec;
//     }
//     cout<<final<<endl;
//     return 0;
// }

// B
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
    ll n=lines.size();
    vector<vector<ll>> seq(n,vector<ll> (2001));
    vector<vector<ll>> diff(n,vector<ll> (2000));
    for(ll i=0;i<n;i++){
        ll sec=stoll(lines[i]);
        seq[i][0]=sec%10;
        for(ll j=1;j<2001;j++){
            ll res=sec*64;
            sec^=res;
            sec%=16777216;
            res=sec/32;
            sec^=res;
            sec%=16777216;
            res=sec*2048;
            sec^=res;
            sec%=16777216;
            seq[i][j]=sec%10;
            diff[i][j-1]=seq[i][j]-seq[i][j-1];
        }
    }
    map<vector<ll>,ll> mp;
    for(ll i=0;i<n;i++){
        map<vector<ll>,ll> mp_temp;
        for(ll j=0;j<2000-3;j++){
            vector<ll> temp;
            for(ll k=0;k<4;k++){
                temp.push_back(diff[i][j+k]);
            }
            if(!mp_temp.count(temp)){
                mp_temp[temp]=seq[i][j+4];
                mp[temp]+=seq[i][j+4];
            }
        }
    }
    ll final=0;
    for(auto it:mp){
        final=max(final,it.second);
    }
    cout<<final<<endl;
    return 0;
}