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
 
const int n=57;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(vector<string> & grid,int x,int y,set<pii> & s1){
    if(grid[x][y]=='9'){
        s1.insert({x,y});
        return;
    }
    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]==(grid[x][y]+1)) dfs(grid,newx,newy,s1);
    }
}

int dfs2(vector<string> & grid,int x,int y){
    if(grid[x][y]=='9') return 1;
    int ans=0;
    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]==(grid[x][y]+1)) ans+=dfs2(grid,newx,newy);
    }
    return ans;
}

//A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> grid(n);
//     for(int i=0;i<n;i++){
//         cin>>grid[i];
//     }
//     ll res=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]=='0'){
//                 set<pii> s1;
//                 dfs(grid,i,j,s1);
//                 res+=s1.size();
//             }
//         }
//     }
//     cout<<res<<endl;
//     return 0;
// }

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='0'){
                res+=dfs2(grid,i,j);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}