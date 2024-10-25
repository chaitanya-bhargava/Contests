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
        long long n;
        cin>>n;
        vector<long long> a(n);
        vector<long long> b(n+1);
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        for(long long i=0;i<n+1;i++){
            cin>>b[i];
        }
        long long extra=b[n];
        long long ans=0;
        long long f=0;
        long long diff=INT_MAX;
        for(long long i=0;i<n;i++){
            ans+=abs(a[i]-b[i]);
            diff=min(diff,abs(extra-a[i]));
            diff=min(diff,abs(extra-b[i]));
            if((b[i]>extra && a[i]<=extra) || (b[i]<extra && a[i]>=extra)) f=1;
        }
        if(f==1){
            cout<<ans+1<<endl;
        }
        else{
            cout<<ans+diff+1<<endl;
        }
    }
    return 0;
}