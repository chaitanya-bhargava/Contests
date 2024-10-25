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
        ll n,k;
        cin>>n>>k;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=0;i<n;i++){
            ll num;
            cin>>num;
            pq.push(num);
        }
        while(k--){
            ll p=pq.top();
            cout<<p<<endl;
            pq.pop();
            pq.push(p*2);
        }
        ll sum=0;
        while(!pq.empty()){
            sum=(sum+pq.top())%mod;
            cout<<pq.top()<<endl;
            pq.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}