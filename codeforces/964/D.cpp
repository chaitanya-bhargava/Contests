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
        string s,t;
        cin>>s;
        cin>>t;
        int i=0;
        int j=0;
        string ans;
        int flag=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                ans.push_back(s[i]);
                i++;
                j++;
            }
            else if(s[i]=='?'){
                ans.push_back(t[j]);
                i++;
                j++;
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
        }
        if(i==s.size() && j<t.size()){
            cout<<"NO"<<endl;
            continue;
        }
        while(i<s.size()){
            if(s[i]=='?') ans.push_back('a');
            else ans.push_back(s[i]);
            i++;
        }
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}