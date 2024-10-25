#include<bits/stdc++.h>
using namespace std;

long long findParent(vector<long long> & parent,int k){
    if(parent[k]==-1) return k;
    return parent[k]=findParent(parent,parent[k]);
}
void Union(vector<long long> & parent,int & i,int & j,vector<int> & c,int & ans){
    long long p=findParent(parent,i);
    long long q=findParent(parent,j);
    if(c[p]!=c[q]){
        ans++;
        return;
    }
    parent[p]=q;
}

int colorfulGraph(int n, int m, vector<vector<int>> &edges, int k, vector<int> &c) {
    vector<long long> parent(n,-1);
    int ans=0;
    for(long long i=0;i<m;i++){
        Union(parent,edges[i][0],edges[i][1],c,ans);
    }
    vector<long long> count(k,0);
    for(long long i=0;i<n;i++){
        if(parent[i]==-1) count[c[i]]++; 
    }
    for(long long i=0;i<k;i++){
        if(count[i]==0) continue;
        ans+=(count[i]-1);
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> c(n);
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        vector<vector<int>> edges;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges.push_back({u,v});
        }
        ofstream outfile;
        outfile.open("afile.text");
        outfile<<colorfulGraph(n,m,edges,k,c)<<endl;
    }
    return 0;
}