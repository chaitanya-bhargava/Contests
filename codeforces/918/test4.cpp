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
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e'){
                ans.push_back(s[i]);
                ans.push_back(s[i+1]);
                ans.push_back('.');
                i++;
            }
            else{
                ans.push_back(s[i]);
                ans.push_back(s[i+1]);
                ans.push_back(s[i+2]);
                ans.push_back('.');
                i++;
                i++;
            }
        }
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}