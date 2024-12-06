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
 
const int n=130;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


int part1(int starti,int startj,vector<string> grid){
    ll res=0;
    int dir=0;
    int x=starti;
    int y=startj;
    while(true){
        grid[x][y]='X';
        int newx=x+dx[dir];
        int newy=y+dy[dir];
        if(newx>=n || newy>=n || newx<0 || newy<0) break;
        if(grid[newx][newy]=='#'){
            dir=(dir+1)%4;
        }
        else{
            x=newx;
            y=newy;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='X') res++;
        }
    }
    return res;
}

//A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> grid(n);
//     for(int i=0;i<n;i++){
//         cin>>grid[i];
//     }
//     int starti=0;
//     int startj=0;
//     int dir=0;
//     int flag=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]=='^'){
//                 starti=i;
//                 startj=j;
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==1) break;
//     }
//     ll res=part1(starti,startj,grid);
//     cout<<res<<endl;
//     return 0;
// }

bool part2(int starti,int startj, vector<string> & grid){
    vector<vector<vector<int>>> visited(n,vector<vector<int>> (n,vector<int> (4,0)));
    int dir=0;
    int x=starti;
    int y=startj;
    visited[x][y][dir]=1;
    bool flag=false;
    while(true){
        int newx=x+dx[dir];
        int newy=y+dy[dir];
        if(newx>=n || newy>=n || newx<0 || newy<0) break;
        if(grid[newx][newy]=='#'){
            dir=(dir+1)%4;
        }
        else{
            x=newx;
            y=newy;
            if(visited[x][y][dir]==1){
                flag=true;
                break;
            }
            visited[x][y][dir]=1;
        }
    }
    return flag;
}


//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    int starti=0;
    int startj=0;
    int dir=0;
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='^'){
                starti=i;
                startj=j;
                flag=1;
                break;
            }
        }
        if(flag==1) break;
    }
    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='.'){
                grid[i][j]='#';
                if(part2(starti,startj,grid)) res++;
                grid[i][j]='.';
            }
        }
    }
    cout<<res<<endl;
    return 0;
}