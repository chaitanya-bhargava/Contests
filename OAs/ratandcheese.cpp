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
 
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int> (n,0));
    queue<pair<int,int>> q;
    int count_cheese=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j]==2) q.push({i,j});
            else if(grid[i][j]==1) count_cheese++;
        }
    }
    vector<vector<int>> visited = grid;
    if (count_cheese == 0)
        return 0;
    if (q.empty())
        return -1;
    int minutes=-1;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for (int i=0;i<4;i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx >= 0 && newx < n && newy >= 0 && newy < n && visited[newx][newy] == 1) {
                    visited[newx][newy] = 2;
                    q.push({newx, newy});
                    count_cheese--;
                }
            }
        }
        minutes++;
    }
    if(count_cheese==0)
    cout<<minutes<<endl;
    else cout<<-1<<endl;
    return 0;
}