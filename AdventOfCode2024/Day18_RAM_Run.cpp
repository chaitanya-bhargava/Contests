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
 
const int n=71;
const int m=3450;

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
//     vector<vector<char>> grid(n,vector<char> (n,'.'));
//     for(int i=0;i<m;i++){
//         int x=stoi(lines[i]);
//         int y=stoi(lines[i].substr(lines[i].find(',')+1));
//         grid[y][x]='#';
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             sso<<grid[i][j];
//         }
//         sso<<endl;
//     }
//     queue<vector<int>> q;
//     q.push({0,0,0});
//     vector<vector<int>> visited(n,vector<int> (n,0));
//     visited[0][0]=1;
//     ll res=0;
//     while(!q.empty()){
//         int x=q.front()[0];
//         int y=q.front()[1];
//         int steps=q.front()[2];
//         if(x==n-1 && y==n-1) res=steps;
//         q.pop();
//         for(int i=0;i<4;i++){
//             int newx=x+dx[i];
//             int newy=y+dy[i];
//             if(newx>=0 && newy>=0 && newx<n && newy<n && visited[newx][newy]==0 && grid[newx][newy]!='#'){
//                 q.push({newx,newy,steps+1});
//                 visited[newx][newy]=1;
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
    vector<string> lines;
    fstream ss("input.txt");
    ofstream sso("output.txt");
    string line;
    while(getline(ss,line)){
        lines.push_back(line);
    }
    vector<vector<char>> grid(n,vector<char> (n,'.'));
    for(int i=0;i<m;i++){
        int x=stoi(lines[i]);
        int y=stoi(lines[i].substr(lines[i].find(',')+1));
        grid[y][x]='#';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sso<<grid[i][j];
            }
            sso<<endl;
        }
        sso<<endl;
        queue<vector<int>> q;
        q.push({0,0,0});
        vector<vector<int>> visited(n,vector<int> (n,0));
        visited[0][0]=1;
        ll res=INT_MAX;
        while(!q.empty()){
            int xt=q.front()[0];
            int yt=q.front()[1];
            int steps=q.front()[2];
            if(xt==n-1 && yt==n-1) res=steps;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=xt+dx[i];
                int newy=yt+dy[i];
                if(newx>=0 && newy>=0 && newx<n && newy<n && visited[newx][newy]==0 && grid[newx][newy]!='#'){
                    q.push({newx,newy,steps+1});
                    visited[newx][newy]=1;
                }
            } 
        }
        if(res==INT_MAX){
            cout<<x<<","<<y<<endl;
            goto end;        
        }
    }
    end:

    return 0;
}