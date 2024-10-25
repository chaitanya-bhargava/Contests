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
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        unordered_map<int,int> ignorable;
        unordered_map<int,int> changes;
        vector<int> b(n);
        int count=0;
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(b[i]!=a[i]){
                if(changes[b[i]]==0) count++;
                changes[b[i]]++;
            }
            else ignorable[b[i]]=1;
        }
        int m;
        cin>>m;
        vector<int> d(m);
        for(int i=0;i<m;i++){
            cin>>d[i];
        }
        int flag=0;
        for(int i=0;i<m;i++){
            if(changes[d[i]]>0){
                changes[d[i]]--;
                if(changes[d[i]]==0){
                    ignorable[d[i]]=1;
                    count--;
                }
            }
            else if(count==0 && ignorable[d[i]]==0){
                flag=1;
            }
            else if(flag==1 && ignorable[d[i]]==1){
                flag=0;
            }
        }
        if(flag==1 || count>0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}