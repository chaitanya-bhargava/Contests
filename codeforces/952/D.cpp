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
        int n,m;
        cin>>n>>m;
        int mini=n+1;
        int maxi=0;
        int minj=m+1;
        int maxj=0;
        for(int i=1;i<n+1;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='#'){
                    mini=min(mini,i);
                    maxi=max(maxi,i);
                    minj=min(minj,j+1);
                    maxj=max(maxj,j+1);
                }
            }
        }
        cout<<(mini+maxi)/2<<" "<<(minj+maxj)/2<<endl;
    }
    return 0;
}