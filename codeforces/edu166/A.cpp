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
        char c='a';
        char d='0';
        bool ans=true;
        bool let=false;
        for(int i=0;i<n;i++){
            if(s[i]<='z' && s[i]>='a'){
                let=true;
                if(s[i]<c){
                    ans=false;
                    break;
                }
                else{
                    c=s[i];
                }
            }
            else{
                if(let){
                    ans=false;
                    break;
                }
                else{
                    if(s[i]<d){
                        ans=false;
                        break;
                    }
                    else{
                        d=s[i];
                    }
                }
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}