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
        int n,x;
        cin>>n>>x;
        int ans=0;
        int num=min(x*x/2,n);
        // cout<<num<<endl;
        for(int i=1;i<num;i++){
            int flag2=0;
            for(int j=1;j<num;j++){
                int flag=0;
                for(int k=1;k<num;k++){
                    if((i*j+j*k+i*k)<=n && (i+j+k)<=x){
                        ans++;
                        flag=1;
                        flag2=1;
                    }
                    else break;
                }
                if(flag==0) break;
            }
            if(flag2==0) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}