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
 
const int n=140;

map<vector<int>,int> corners;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

pair<ll,ll> bfs(vector<string> & grid,int i,int j,vector<vector<int>> & visited){
    char ch=grid[i][j];
    queue<pii> q;
    q.push({i,j});
    visited[i][j]=1;
    pair<ll,ll> ans={0,0};

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        ans.first++;
        for(int k=0;k<4;k++){
            int newx=x+dx[k];
            int newy=y+dy[k];
            if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]==ch){
                if(visited[newx][newy]==0){
                    q.push({newx,newy});
                    visited[newx][newy]=1;
                }
            }
            else{
                ans.second++;
            }
        }
    }
    return ans;
}

pair<ll,ll> bfs2(vector<string> & grid,int i,int j,vector<vector<int>> & visited){
    char ch=grid[i][j];
    queue<pii> q;
    q.push({i,j});
    visited[i][j]=1;
    pair<ll,ll> ans={0,0};

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        ans.first++;
        vector<int> dir(4,0);
        for(int k=0;k<4;k++){
            int newx=x+dx[k];
            int newy=y+dy[k];
            if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]==ch){
                if(visited[newx][newy]==0){
                    q.push({newx,newy});
                    visited[newx][newy]=1;
                }
                dir[k]=1;
            }
        }
        // cout<<x<<" "<<y<<" "<<grid[x][y]<<endl;
        // for(auto x:dir){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        int corner_state=corners[dir];
        if(corner_state>0){
            ans.second+=corner_state;
        }
        else{
            switch (corner_state)
            {
            case -1:
                if(grid[x+1][y+1]!=ch) ans.second++;
                if(grid[x-1][y+1]!=ch) ans.second++;
                if(grid[x+1][y-1]!=ch) ans.second++;
                if(grid[x-1][y-1]!=ch) ans.second++;
                break;
            case -2:
                ans.second++;
                if(grid[x+1][y+1]!=ch) ans.second++;
                break;
            case -3:
                ans.second++;
                if(grid[x-1][y+1]!=ch) ans.second++;
                break;
            case -4:
                ans.second++;
                if(grid[x+1][y-1]!=ch) ans.second++;
                break;
            case -5:
                ans.second++;
                if(grid[x-1][y-1]!=ch) ans.second++;
                break;
            case -6:
                if(grid[x+1][y-1]!=ch) ans.second++;
                if(grid[x-1][y-1]!=ch) ans.second++;
                break;
            case -7:
                if(grid[x+1][y+1]!=ch) ans.second++;
                if(grid[x-1][y+1]!=ch) ans.second++;
                break;
            case -8:
                if(grid[x-1][y+1]!=ch) ans.second++;
                if(grid[x-1][y-1]!=ch) ans.second++;
                break;
            case -9:
                if(grid[x+1][y+1]!=ch) ans.second++;
                if(grid[x+1][y-1]!=ch) ans.second++;
                break;
            
            default:
                break;
            }
        }
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
//     vector<vector<int>> visited(n,vector<int> (n,0));
//     ll res=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(visited[i][j]==0){
//                 pair<ll,ll> temp=bfs(grid,i,j,visited);
//                 res+=temp.first*temp.second;
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
    corners[{0,0,0,0}]=4;
    corners[{1,1,1,1}]=-1;
    corners[{0,0,0,1}]=2;
    corners[{0,0,1,0}]=2;
    corners[{0,1,0,0}]=2;
    corners[{1,0,0,0}]=2;
    corners[{1,1,0,0}]=0;
    corners[{0,0,1,1}]=0;
    corners[{1,0,1,0}]=-2;
    corners[{1,0,0,1}]=-3;
    corners[{0,1,1,0}]=-4;
    corners[{0,1,0,1}]=-5;
    corners[{0,1,1,1}]=-6;
    corners[{1,0,1,1}]=-7;
    corners[{1,1,0,1}]=-8;
    corners[{1,1,1,0}]=-9;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    vector<vector<int>> visited(n,vector<int> (n,0));
    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0){
                pair<ll,ll> temp=bfs2(grid,i,j,visited);
                cout<<grid[i][j]<<" "<<temp.first<<" "<<temp.second<<endl;
                res+=temp.first*temp.second;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
