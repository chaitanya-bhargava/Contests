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
       int flag=0;
       int val=-1;
       for(int i=1;i*i<1000000;i++){
            if(n%(i*i*2)==0){
                flag=1;
                val=i*i;
            }
       }
       if(flag==0){
        cout<<-1<<endl;
       }
       else{
        int k=1;
        int freq=n/val;
        for(int i=0;i<freq/2;i++){
            for(int j=k;j<k+val;j++){
                cout<<j<<" ";
            }
            for(int j=k;j<k+val;j++){
                cout<<j<<" ";
            }
            k+=val;
        }
        cout<<endl;
        cout<<val<<endl;
       }
    }
    return 0;
}