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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        map<pair<int,int>,int> Alice;
        string s;
        cin>>s;
        if((a+b)%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        int x=0;
        int y=0;
        unordered_map<char,int> mp;
        mp['U']=0;
        mp['D']=1;
        mp['R']=2;
        mp['L']=3;
        int flag=0;
        for(int i=0;i<n;i++){
            cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
            x=x+dx[mp[s[i]]];
            y=y+dy[mp[s[i]]];
            if(a==x){
                if(b>y) b--;
                else b++;
            }
            else if(a>x){
                a--;
            }
            else if(a<x){
                a++;
            }
            if(a==x && b==y){
                flag=1;
                break;
            }
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}