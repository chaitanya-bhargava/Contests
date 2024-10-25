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
        string s,t;
        cin>>s;
        cin>>t;
        if(s==t){
            cout<<0<<endl;
            continue;
        }
        if(s[0]!=t[0]){
            cout<<-1<<endl;
            continue;
        }
        if(s.size()>t.size()){
            if(s.compare(0,t.size(),t)==0){
                cout<<1<<endl;
                continue;
            }
            int i=0;int j=0;
            while(i<n && j<m && s[i]==t[j]){
                i++;
                j++;
            }
            int diff=s.size()-t.size();
            i=i+diff;
            while(i<n && j<m && s[i]==t[j]){
                i++;
                j++;
            }
            if(i==n && j==m){
                cout<<1<<endl;
                continue;
            }
        }
        else if(t.size()>s.size()){
            if(t.compare(0,s.size(),s)==0){
                cout<<1<<endl;
                continue;
            }
            int i=0;int j=0;
            while(i<n && j<m && s[i]==t[j]){
                i++;
                j++;
            }
            int diff=t.size()-s.size();
            j=j+diff;
            while(i<n && j<m && s[i]==t[j]){
                i++;
                j++;
            }
            if(i==n && j==m){
                cout<<1<<endl;
                continue;
            }
        }
        cout<<2<<endl;
    }
    return 0;
}