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
        int n,f,k;
        cin>>n>>f>>k;
        vector<int> cubes(n);
        int fav;
        for(int i=0;i<n;i++){
            cin>>cubes[i];
            if(i==f-1) fav=cubes[i];
        }
        sort(cubes.begin(),cubes.end(),greater<int>());
        string ans="NO";
        for(int i=0;i<k;i++){
            if(cubes[i]==fav){
                ans="YES";
            }
        }
        if(ans=="YES" && k<n && cubes[k]==fav) ans="MAYBE";
        cout<<ans<<endl;
    }
    return 0;
}