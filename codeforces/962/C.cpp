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
        int n,q;
        cin>>n>>q;
        string a,b;
        cin>>a>>b;
        vector<int> ct;
        vector<int> ct2;
        vector<int> zeros(26,0);
        int sum=0;
        
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         cout<<i<<" "<<j<<" "<<mp[i][j]<<endl;
        //     }
        // }
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            for(int i=0;i<n;i++){
                ct=zeros;
                ct2=zeros;
                for(int j=i;j<n;j++){
                    sum=0;
                    ct[a[j]-'a']++;
                    ct2[b[j]-'a']++;
                    for(int k=0;k<26;k++){
                        sum+=abs(ct[k]-ct2[k]);
                    }
                    mp[i][j]=sum/2;
                }
            }
            // cout<<"ANS:"<<endl;
            cout<<mp[x-1][y-1]<<endl;
        }
    }
    return 0;
}