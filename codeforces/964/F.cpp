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
 
long long nCr(int n, int r){
        if (r > n){
            return 0;
        }
        long long numerator = 1;
        long long denominator = 1;
        
        for (int i = 0; i < r; i++){
            numerator = (numerator * (n - i)) % mod;
            denominator = (denominator * (i + 1)) % mod;
        }
        
        long long inverse = 1;
        long long base = denominator;
        long long power = mod - 2;
        while (power > 0){
            if (power & 1){
                inverse = (inverse * base) % mod;
            }
            base = (base * base) % mod;
            power >>= 1;
        }
        
        long long result = (numerator * inverse) % mod;
        return result;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        int count1=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1) count1++;
        }
        int need1=(k+1)/2;
        long long ans=0;
        for(int i=need1;i<=k;i++){
            ans=(ans+nCr(count1,i)*nCr(n-count1,k-i))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}