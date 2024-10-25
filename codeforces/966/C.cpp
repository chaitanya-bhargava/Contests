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
        vector<long long> a(n);
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;
        for(long long i=0;i<m;i++){
            string s;
            cin>>s;
            int l=s.size();
            int flag=0;
            if(l!=n){
                cout<<"NO"<<endl;
                continue;
            }
            vector<long long> mp(26,1000000005);
            map<long long,char> mp2;
            for(long long j=0;j<l;j++){
                if(mp[s[j]-'a']!=1000000005 && mp[s[j]-'a']!=a[j]){
                    flag=1;
                    break;
                }
                if(mp2.find(a[j])!=mp2.end() && mp2[a[j]]!=s[j]){
                    flag=1;
                    break;
                }
                mp[s[j]-'a']=a[j];
                mp2[a[j]]=s[j];
            }
            if(flag==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}