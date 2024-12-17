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
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

// A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> lines;
//     fstream ss("input.txt");
//     string line;
//     while(getline(ss,line)){
//         lines.push_back(line);
//     }
//     vector<string> grid;
//     for(auto x:lines){
//         grid.push_back(x);
//     }
//     int n=grid.size();
//     int m=grid[0].size();
//     int starti=n-2;
//     int startj=1;
//     priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
//     pq.push({0,starti,startj,0});
//     vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
//     dist[starti][startj]=0;
//     while(!pq.empty()){
//         vector<int> temp=pq.top();
//         pq.pop();
//         int x=temp[1];
//         int y=temp[2];
//         int c=temp[0];
//         int dir=temp[3];
//         if(grid[x][y]=='E') break;
//         // cout<<x<<" "<<y<<" "<<c<<endl;
//         int newx=x+dx[dir];
//         int newy=y+dy[dir];
//         if(grid[newx][newy]!='#' && dist[newx][newy]>(c-1001)){
//             pq.push({c+1,newx,newy,dir});
//             dist[newx][newy]=min(dist[newx][newy],c+1);
//         }
//         newx=x+dx[(dir+1)%4];
//         newy=y+dy[(dir+1)%4];
//         if(grid[newx][newy]!='#' && dist[newx][newy]>(c-1001)){
//             pq.push({c+1001,newx,newy,(dir+1)%4});
//             dist[newx][newy]=min(dist[newx][newy],c+1001);
//         }
//         newx=x+dx[((dir-1)%4+4)%4];
//         newy=y+dy[((dir-1)%4+4)%4];
//         if(grid[newx][newy]!='#' && dist[newx][newy]>(c-1001)){
//             pq.push({c+1001,newx,newy,((dir-1)%4+4)%4});
//             dist[newx][newy]=min(dist[newx][newy],c+1001);
//         }
//     }
//     cout<<dist[1][m-2]<<endl;
//     return 0;
// }

vector<string> grid2;

void helper(int x,int y,int dir,int & cost,vector<pii> & path,set<pii> & sf,vector<vector<int>> & dist){
    if(x==1 && y==dist[0].size()-2){
        if(dist[x][y]==cost){
            for(auto it:path){
                grid2[it.first][it.second]='O';
                sf.insert(it);
            }
        }
        else{
            return;
        }
    }
    int newx=x+dx[dir];
    int newy=y+dy[dir];
    int flag=0;
    if(dist[newx][newy]==dist[x][y]+1){
        path.push_back({newx,newy});
        flag=1;
        helper(newx,newy,dir,cost,path,sf,dist);
        path.pop_back();
    }
    int newx2=newx+dx[dir];
    int newy2=newy+dy[dir];
    if(flag==0 && dist[newx][newy]!=INT_MAX && dist[newx2][newy2]==dist[x][y]+2){
        path.push_back({newx,newy});
        path.push_back({newx2,newy2});
        helper(newx2,newy2,dir,cost,path,sf,dist);
        path.pop_back();
        path.pop_back();
    }
    newx=x+dx[(dir+1)%4];
    newy=y+dy[(dir+1)%4];
    if(dist[newx][newy]!=INT_MAX && dist[newx][newy]==dist[x][y]+1001){
        path.push_back({newx,newy});
        helper(newx,newy,(dir+1)%4,cost,path,sf,dist);
        path.pop_back();
    }
    newx=x+dx[((dir-1)%4+4)%4];
    newy=y+dy[((dir-1)%4+4)%4];
    if(dist[newx][newy]!=INT_MAX && dist[newx][newy]==dist[x][y]+1001){
        path.push_back({newx,newy});
        helper(newx,newy,((dir-1)%4+4)%4,cost,path,sf,dist);
        path.pop_back();
    }
}

// B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> lines;
    fstream ss("input.txt");
    string line;
    while(getline(ss,line)){
        lines.push_back(line);
    }
    vector<string> grid;
    for(auto x:lines){
        grid.push_back(x);
    }
    grid2=grid;
    int n=grid.size();
    int m=grid[0].size();
    int starti=n-2;
    int startj=1;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,starti,startj,0});
    vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
    dist[starti][startj]=0;
    while(!pq.empty()){
        vector<int> temp=pq.top();
        pq.pop();
        int x=temp[1];
        int y=temp[2];
        int c=temp[0];
        int dir=temp[3];
        if(grid[x][y]=='E') break;
        int newx=x+dx[dir];
        int newy=y+dy[dir];
        if(grid[newx][newy]!='#' && dist[newx][newy]>(c-1001)){
            pq.push({c+1,newx,newy,dir});
            dist[newx][newy]=min(dist[newx][newy],c+1);
        }
        newx=x+dx[(dir+1)%4];
        newy=y+dy[(dir+1)%4];
        if(grid[newx][newy]!='#' && dist[newx][newy]>(c-1001)){
            pq.push({c+1001,newx,newy,(dir+1)%4});
            dist[newx][newy]=min(dist[newx][newy],c+1001);
        }
        newx=x+dx[((dir-1)%4+4)%4];
        newy=y+dy[((dir-1)%4+4)%4];
        if(grid[newx][newy]!='#' && dist[newx][newy]>(c-1001)){
            pq.push({c+1001,newx,newy,((dir-1)%4+4)%4});
            dist[newx][newy]=min(dist[newx][newy],c+1001);
        }
    }
    int final=dist[1][m-2];
    vector<pii> path;
    set<pii> sf;
    path.push_back({n-2,1});
    helper(n-2,1,0,final,path,sf,dist);
    for(auto it:grid2){
        cout<<it<<endl;
    }
    cout<<sf.size()<<endl;
    return 0;
}