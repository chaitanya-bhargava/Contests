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
int dx[]={0,0,-1,-1,-1,1,1,1};
int dy[]={1,-1,0,1,-1,0,1,-1};
string xmas="XMAS";

long long find(vector<string> & grid,int starti,int startj){
    long long ans=0;
    int x=starti;
    int y=startj;
    for(int i=0;i<8;i++){
        int flag=0;
        // cout<<"START:"<<i<<" "<<x<<" "<<y<<endl;
        for(int j=1;j<4;j++){
            int newx=x+j*dx[i];
            int newy=y+j*dy[i];
            // cout<<newx<<" "<<newy<<" "<<j<<" "<<grid[newx][newy]<<" "<<xmas[j]<<endl;
            if(newx<0 || newx>=n || newy>=n || newy<0 || grid[newx][newy]!=xmas[j]){
                flag=1;
                break;
            }
        }
        if(flag==0) ans++;
    }
    return ans;
}

int dx2[]={-1,-1,1,1};
int dy2[]={-1,1,1,-1};

long long find2(vector<string> & grid,int starti,int startj){
    long long ans=0;
    int x=starti;
    int y=startj;
    for(int i=0;i<4;i++){
        int sx1=x+dx2[i];
        int sx2=x+dx2[(i+1)%4];
        int mx1=x+dx2[(i+2)%4];
        int mx2=x+dx2[(i+3)%4];
        int sy1=y+dy2[i];
        int sy2=y+dy2[(i+1)%4];
        int my1=y+dy2[(i+2)%4];
        int my2=y+dy2[(i+3)%4];
        // cout<<sx1<<" "<<sy1<<" "<<sx2<<" "<<sy2<<" "<<mx1<<" "<<mx2<<" "<<my1<<" "<<my2<<endl;
        if(sx1>=0 && sx2>=0 && mx1>=0 && mx2>=0 && sy1>=0 && sy2>=0 && my1>=0 && my2>=0 && sx1<n && sx2<n && mx1<n && mx2<n && sy1<n && sy2<n && my1<n && my2<n && grid[sx1][sy1]=='S' && grid[sx2][sy2]=='S' && grid[mx1][my1]=='M' && grid[mx2][my2]=='M') ans++;
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
//     long long res=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]=='X'){
//                 res+=find(grid,i,j);
//                 // cout<<res<<endl;
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
    long long res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='A'){
                res+=find2(grid,i,j);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}