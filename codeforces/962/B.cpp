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
        int n,k;
        cin>>n>>k;
        vector<vector<int>> ans(n/k,vector<int> (n/k,0));
        for(int i=0;i<n;i++){
            string row;
            cin>>row;
            if(i%k==0){
                for(int j=0;j<n;j+=k){
                    if(row[j]=='1') ans[i/k][j/k]=1;
                }
            }
        }
        // cout<<"ANS:"<<endl;
        for(int i=0;i<n/k;i++){
            for(int j=0;j<n/k;j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}