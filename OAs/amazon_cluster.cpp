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
 
long getMaxThroughput(vector<int> host_throughput){
    sort(host_throughput.begin(),host_throughput.end());
    int n=host_throughput.size();
    int grps=n/3;
    int ans=0;
    int i=n-2;
    while(grps--){
        ans+=host_throughput[i];
        i-=2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> host_throughput(n);
    for(int i=0;i<n;i++){
        cin>>host_throughput[i];
    }
    long res=getMaxThroughput(host_throughput);
    cout<<res<<endl;
    return 0;
}