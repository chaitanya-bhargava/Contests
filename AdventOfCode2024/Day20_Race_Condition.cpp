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
 
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

// A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> lines;
//     fstream ss("input.txt");
//     ofstream sso("output.txt");
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
//     int starti=0;
//     int startj=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(grid[i][j]=='S'){
//                 starti=i;
//                 startj=j;
//             }
//         }
//     }
//     vector<vector<int>> dist(n,vector<int> (m,-1));
//     dist[starti][startj]=0;
//     int x=starti;
//     int y=startj;
//     while(grid[x][y]!='E'){
//         for(int i=0;i<4;i++){
//             int newx=x+dx[i];
//             int newy=y+dy[i];
//             if(grid[newx][newy]!='#' && dist[newx][newy]==-1){
//                 dist[newx][newy]=dist[x][y]+1;
//                 x=newx;
//                 y=newy;
//                 break;
//             }
//         }
//     }
//     ll res=0;
//     for(int i=1;i<n-1;i++){
//         for(int j=1;j<n-1;j++){
//             if(dist[i][j]==-1 && dist[i][j-1]!=-1 && dist[i][j+1]!=-1){
//                 int saved=abs(dist[i][j-1]-dist[i][j+1])-2;
//                 if(saved>=100) res++;
//             }
//             if(dist[i][j]==-1 && dist[i-1][j]!=-1 && dist[i+1][j]!=-1){
//                 int saved=abs(dist[i-1][j]-dist[i+1][j])-2;
//                 if(saved>=100) res++;
//             }
//         }
//     }
//     cout<<res<<endl;
//     return 0;
// }

int manDist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

// B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> lines;
    fstream ss("input.txt");
    ofstream sso("output.txt");
    string line;
    while(getline(ss,line)){
        lines.push_back(line);
    }
    vector<string> grid;
    for(auto x:lines){
        grid.push_back(x);
    }
    int n=grid.size();
    int m=grid[0].size();
    int starti=0;
    int startj=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='S'){
                starti=i;
                startj=j;
            }
        }
    }
    vector<vector<int>> dist(n,vector<int> (m,-1));
    dist[starti][startj]=0;
    int x=starti;
    int y=startj;
    while(grid[x][y]!='E'){
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(grid[newx][newy]!='#' && dist[newx][newy]==-1){
                dist[newx][newy]=dist[x][y]+1;
                x=newx;
                y=newy;
                break;
            }
        }
    }
    ll res=0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(dist[i][j]==-1) continue;
            for(int k=1;k<n-1;k++){
                for(int l=1;l<m-1;l++){
                    if(dist[k][l]==-1) continue;
                    int skip=manDist(i,j,k,l);
                    if(skip<=20){
                        int saved=abs(dist[i][j]-dist[k][l])-skip;
                        if(saved>=100) res++;
                    }
                }
            }
        }
    }
    cout<<res/2<<endl;
    return 0;
}