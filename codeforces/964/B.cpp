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
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        int ans=0;
        //a1,b1 a2,b2
        if(a1>b1){
            if(a2>=b2) ans++;
        }
        else if(a1==b1){
            if(a2>b2) ans++;
        }
        //a1,b2 a2,b1
        if(a1>b2){
            if(a2>=b1) ans++;
        }
        else if(a1==b2){
            if(a2>b1) ans++;
        }
        //a2,b1 a1,b2
        if(a2>b1){
            if(a1>=b2) ans++;
        }
        else if(a2==b1){
            if(a1>b2) ans++;
        }
        //a2,b2 a1,b1
        if(a2>b2){
            if(a1>=b1) ans++;
        }
        else if(a2==b2){
            if(a1>b1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}