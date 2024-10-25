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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int flag=0;
        int ct=2;
        vector<vector<int>> grid(n,vector<int> (m,2));
        if(n<=m){
            int j=0;
            for(;j<n;j++){
                grid[j][j]=3;
            }
            while(j<m){
                grid[n-1][j]=3;
                j++;
            }
        }
        else{
            int i=0;
            for(;i<m;i++){
                grid[i][i]=3;
            }
            while(i<n){
                grid[i][m-1]=3;
                i++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}