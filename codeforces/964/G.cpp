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
        int l=2;
        int r=499;
        while(l<r){
            cout<<"? "<<l<<" "<<r<<endl;
            cout.flush();
            int ans;
            cin>>ans;
            if(ans==l*r){
                l=r+1;
                r=9999;
            }
            else if(ans==l*(r+1)){
                l++;
                r=r/2;
            }
            else{
                r=l-1;
                l=2;
            }
        }
        cout<<"! "<<r<<endl;
    }
    return 0;
}