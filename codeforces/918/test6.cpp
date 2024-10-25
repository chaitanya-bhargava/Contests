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
        int n;
        cin>>n;
        V<pii> arr;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            arr.push_back({a,b});
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int num=arr[i].second;
            for(int j=i+1;j<n;j++){
                if(arr[j].second<num) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}