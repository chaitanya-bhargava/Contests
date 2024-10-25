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
        ll n;
        cin>>n;
        vector<vector<ll>> g(n+1);
        for(int i=2;i<n+1;i++){
            cout<<"? 1 "<<i<<endl;
            cout.flush();
            int a;
            cin>>a;
            if(a==-1) break;
            if(a==1){
                g[1].push_back(i);
                g[i].push_back(1);
            }
            else{
                ll temp=a;
                ll b=0;
                ll flag=0;
                while(true){
                    cout<<"? "<<temp<<" "<<i<<endl;
                    cout.flush();
                    cin>>b;
                    if(b==-1){
                        flag=1;
                        break;
                    }
                    if(temp==b) break;
                    else temp=b;
                }
                if(flag==1) break;
                g[i].push_back(b);
                g[b].push_back(i);
            }
        }
        set<pair<ll,ll>> res;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<g[i].size();j++){
                if(i>g[i][j]) res.insert({g[i][j],i});
                else res.insert({i,g[i][j]});
            }
        }
        cout<<"! ";
        for(auto it:res){
            cout<<it.first<<" "<<it.second<<" ";
        }
        cout<<endl;
    }
    return 0;
}