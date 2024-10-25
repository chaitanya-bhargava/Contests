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
        vector<vector<pii>> g1(n+1);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g1[u].push_back({v,w});
            g1[v].push_back({u,w});
        }
        vector<int> s(n+1);
        for(int i=0;i<n;i++){
            cin>>s[i+1];
        }
        queue<int> q;
        vector<int> curr_slow(n+1,-1);
        vector<int> distance(n+1,INT_MAX);
        distance[1]=0;
        q.push(1);
        curr_slow[1]=s[1];
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cout<<"X: "<<x<<endl;
            cout<<"DISTANCE:"<<endl;
            for(int i=0;i<distance.size();i++){
                cout<<distance[i]<<" ";
            }
            cout<<endl<<"CURR_SLOW :"<<endl;
            for(int i=0;i<curr_slow.size();i++){
                cout<<curr_slow[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<g1[x].size();i++){
                int k=g1[x][i].first;
                if(curr_slow[k]!=-1 && curr_slow[k]<=curr_slow[x]){
                    continue;
                }
                distance[k]=min(distance[k],distance[x]+curr_slow[x]*g1[x][i].second);
                if(curr_slow[k]==-1){
                    curr_slow[k]=min(curr_slow[x],s[k]);
                }
                else{
                    curr_slow[k]=curr_slow[x];
                    distance[k]=distance[x]+curr_slow[x]*g1[x][i].second;
                }
                // curr_slow[k]=min(curr_slow[x],s[k]);
                q.push(k);
            }
        }
        cout<<"ANS: "<<distance[n]<<endl;
    }
    return 0;
}