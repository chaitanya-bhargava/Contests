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
 
int power(long long x, unsigned int y, int p) 
{ 
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) 
    {  
        if (y & 1) res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin>>t;
    vector<int> ns(t);
    vector<int> ks(t);
    for(int i=0;i<t;i++){
        cin>>ns[i];
    }
    for(int i=0;i<t;i++){
        cin>>ks[i];
    }
    for(int i=0;i<t;i++){
        cout<<power(2,ks[i],mod)<<endl;
    }
    return 0;
}