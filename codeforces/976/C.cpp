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
        ll b,c,d;
        cin>>b>>c>>d;
        ll a=0;
        int flag=0;
        for(int i=0;i<61;i++){
            if((d>>i)&1){
                if(!((b>>i)&1) && !((c>>i)&1)){
                    a=a|(1<<i);
                }
                else if(((b>>i)&1));
                else{
                    flag=1;
                    break;
                }
            }
            else{
                if(((b>>i)&1) && ((c>>i)&1)){
                    a=a|(1<<i);
                }
                else if(!((b>>i)&1));
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1) cout<<-1<<endl;
        else cout<<a<<endl;
    }
    return 0;
}