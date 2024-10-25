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
 
void bfs(vector<vector<pair<ll,ll>>> & g1,vector<ll> & horse,vector<pair<ll,ll>> & dist,ll start){
    queue<pair<ll,ll>> q;
    q.push({start,horse[start]});
    while(!q.empty()){
        ll x=q.front().first;
        ll flag=q.front().second;
        q.pop();
        for(auto it:g1[x]){
            if(flag==0){
                if((dist[x].first+it.second)<dist[it.first].first){
                    int newdist=dist[x].first+it.second;
                    dist[it.first].first=newdist;
                    if(horse[it.first]==1){
                        dist[it.first].second=dist[it.first].first;
                        q.push({it.first,1});
                    }
                    else q.push({it.first,0});
                }
            }
            else{
                if((dist[x].second+it.second/2)<dist[it.first].second){
                    dist[it.first].second=(dist[x].second+it.second/2);
                    q.push({it.first,1});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,m,h;
        cin>>n>>m>>h;
        vector<ll> horse(n+1,0);
        for(int i=0;i<h;i++){
            int v;
            cin>>v;
            horse[v]=1;
        }
        vector<vector<pair<ll,ll>>> g1(n+1);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g1[u].push_back({v,w});
            g1[v].push_back({u,w});
        }
        vector<pair<ll,ll>> d1(n+1,{INT_MAX,INT_MAX});
        vector<pair<ll,ll>> d2(n+1,{INT_MAX,INT_MAX});
        d1[1].first=0;
        if(horse[1]==1) d1[1].second=0;
        d2[n].first=0;
        if(horse[n]==1) d2[n].second=0;
        bfs(g1,horse,d1,1);
        bfs(g1,horse,d2,n);
        // cout<<endl<<endl;
        // for(int i=1;i<n+1;i++){
        //     cout<<d1[i].first<<" "<<d1[i].second<<" ";
        // }
        // cout<<endl;
        // for(int i=1;i<n+1;i++){
        //     cout<<d2[i].first<<" "<<d2[i].second<<" ";
        // }
        // cout<<endl;
        // cout<<endl<<endl;
        long long ans=INT_MAX;
        for(int i=1;i<n+1;i++){
            ans=min(ans,max(min(d1[i].first,d1[i].second),min(d2[i].first,d2[i].second)));
        }
        if(ans==INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
        // cout<<endl<<endl;
    }
    return 0;
}