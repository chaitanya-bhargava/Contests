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
 
bool valid(vector<long long> & a,vector<ll> & c,ll & mid,ll & h){
    long long dmg=0;
    for(int i=0;i<a.size();i++){
        dmg+=a[i]*ceil((long double)mid/c[i]);
        if(dmg>=h || dmg==LLONG_MIN) return true;
        // cout<<"DMG: "<<dmg<<endl;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long h,n;
        cin>>h>>n;
        vector<long long> a(n);
        vector<long long> c(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        ll l=1;
        ll r=LLONG_MAX;
        while(l<r){
            ll mid=l+(r-l)/2;
            if(valid(a,c,mid,h)){
                r=mid;
            }
            else{
                l=mid+1;
            }
            // cout<<l<<" "<<r<<" "<<mid<<endl;
        }
        cout<<l<<endl;
    }
    return 0;
}