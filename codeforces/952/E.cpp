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
        long long xt,yt,zt,k;
        cin>>xt>>yt>>zt>>k;
        // long long x,y,z;
        // if(xt>=yt && xt>=zt){
        //     x=xt;
        //     if(yt>=zt){
        //         y=yt;
        //         z=zt;
        //     }
        //     else{
        //         y=zt;
        //         z=yt;
        //     }
        // }
        // else if(yt>=xt && yt>=zt){
        //     x=yt;
        //     if(xt>=zt){
        //         y=xt;
        //         z=zt;
        //     }
        //     else{
        //         y=zt;
        //         z=xt;
        //     }
        // }
        // else{
        //     x=zt;
        //     if(yt>=xt){
        //         y=yt;
        //         z=xt;
        //     }
        //     else{
        //         y=xt;
        //         z=yt;
        //     } 
        // }
        long long x2=-1,y2=-1,z2=-1;
        long long kt=k;
        for(long long i = zt; i >= 1; i--){
            if(k%i==0){
                z2=i;
                k=k/i;
                break;
            }
        }
        for(long long i = yt; i >= 1; i--){
            if(k%i==0){
                y2=i;
                k=k/i;
                break;
            }
        }
        for(long long i = xt; i >= 1; i--){
            if(k%i==0){
                x2=i;
                k=k/i;
                break;
            }
        }
        // cout<<x2<<" "<<y2<<" "<<z2<<endl;
        if(k!=1){
            cout<<0<<endl;
            continue;
        }
        long long ans=1;
        if(xt>=x2 && yt>=y2 && zt>=z2) ans=max(ans,(xt-x2+1)*(yt-y2+1)*(zt-z2+1));
        if(xt>=x2 && yt>=z2 && zt>=y2) ans=max(ans,(xt-x2+1)*(yt-z2+1)*(zt-y2+1));
        if(xt>=y2 && yt>=x2 && zt>=z2) ans=max(ans,(xt-y2+1)*(yt-x2+1)*(zt-z2+1));
        if(xt>=y2 && yt>=z2 && zt>=x2) ans=max(ans,(xt-y2+1)*(yt-z2+1)*(zt-x2+1));
        if(xt>=z2 && yt>=x2 && zt>=y2) ans=max(ans,(xt-z2+1)*(yt-x2+1)*(zt-y2+1));
        if(xt>=z2 && yt>=y2 && zt>=x2) ans=max(ans,(xt-z2+1)*(yt-y2+1)*(zt-x2+1));
        cout<<ans<<endl;
    }
    return 0;
}