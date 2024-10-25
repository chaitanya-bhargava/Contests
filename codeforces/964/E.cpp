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
        int l,r;
        cin>>l>>r;
        if(l%3==1){
            int dummy=l+1;
            int trip=l;
            int ans=0;
            while(dummy!=0){
                ans++;
                dummy/=3;
                trip*=3;
            }
            ans+=(int)(log(trip)/log(3))+1;
            for(int i=l+2;i<=r;i++){
                ans+=(int)(log(i)/log(3))+1;
            }
            cout<<ans<<endl;
        }
        else if(l%3==2){
            int dummy=l;
            int trip=l+1;
            int ans=0;
            while(dummy!=0){
                ans++;
                dummy/=3;
                trip*=3;
            }
            ans+=(int)(log(trip)/log(3))+1;
            for(int i=l+2;i<=r;i++){
                ans+=(int)(log(i)/log(3))+1;
            }
            cout<<ans<<endl;
        }
        else{
            
        }
    }
    return 0;
}