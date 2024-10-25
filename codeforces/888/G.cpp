#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<long long>> & g,long long start,long long dest,long long energy,vector<long long> & h,vector<vector<unordered_map<long long,int>>> & dp){
    priority_queue<pair<long long,long long>> q;
    vector<long long> visited(g.size(),0);
    q.push({energy,start});
    while(!q.empty()){
        long long e=q.top().first;
        long long x=q.top().second;
        q.pop();
        if(x==dest){
            dp[x][dest][e]=1;
            return true;
        }
        if(dp[x][dest][e]==1) return true;
        if(dp[x][dest][e]==2) return false;
        for(auto it:g[x]){
            if(visited[it]==1) continue;
            if(e>=(h[it]-h[x])){
                q.push({e-(h[it]-h[x]),it});
                visited[it]=1;
            }
        }
    }
    dp[start][dest][energy]=2;
    return false;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<long long> heights(n+1);
        vector<vector<long long>> g(n+1);
        for(long long i=1;i<n+1;i++){
            cin>>heights[i];
        }
        for(long long i=0;i<m;i++){
            long long u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long q;
        cin>>q;
        vector<vector<unordered_map<long long,int>>> dp(n+1,vector<unordered_map<long long,int>> (n+1));
        for(long long i=0;i<q;i++){
            long long a,b,e;
            cin>>a>>b>>e;
            if(bfs(g,a,b,e,heights,dp)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}