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
        vector<int> b(n-1);
        for(int i=0;i<n-1;i++){
            b[i]=__gcd(a[i],a[i+1]);
        }
        // for(int i=0;i<n-1;i++){
        //     cout<<b[i]<<" ";
        // }
        // cout<<endl;
        int flag1=0;
        for(int i=2;i<n-1;i++){
            if(b[i]<b[i-1]){
                flag1=1;
                break;
            }
        }
        if(flag1==0){
            cout<<"YES"<<endl;
            continue;
        }
        int flag2=0;
        for(int i=1;i<n-2;i++){
            if(b[i]<b[i-1]){
                flag2=1;
                break;
            }
        }
        if(flag2==0){
            cout<<"YES"<<endl;
            continue;
        }
        int ind=-1;
        for(int i=1;i<n;i++){
            if(b[i]<b[i-1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            cout<<"YES"<<endl;
            continue;
        }
        // cout<<"IND:"<<ind<<endl;
        int flag=0;
        int l=0;
        for(int i=1;i<n-1;i++){
            if(i==ind){
                int newgcd=__gcd(a[i-1],a[i+1]);
                if(newgcd<l){
                    flag=1;
                    break;
                }
                l=newgcd;
                i++;
            }
            else if(b[i]<b[i-1]){
                flag=1;
                break;
            }
            else{
                if(l==1) l=0;
                l=b[i-2];
            }
        }  
        if(flag==0){
            cout<<"YES"<<endl;
            continue;
        }
        if(ind!=n-2) ind++;
        flag=0;
        l=0;
        for(int i=1;i<n-1;i++){
            if(i==ind){
                int newgcd=__gcd(a[i-1],a[i+1]);
                if(newgcd<l){
                    flag=1;
                    break;
                }
                l=newgcd;
            }
            else if(b[i]<b[i-1]){
                flag=1;
                break;
            }
            else{
                l++;
            }
        }  
        if(flag==0){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}