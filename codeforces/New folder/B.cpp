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
        vector<int> a(n+1);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int flag=0;
        vector<int> a2(n+1);
        for(int i=0;i<n;i++){
            a2[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            int j=a2[i];
            // cout<<i<<" "<<j<<" "<<a[j]<<" "<<a2[i]<<endl;
            while(j>i-1){
                // cout<<i<<" "<<j<<" "<<a[j]<<" "<<a2[i]<<endl;
                if(abs(a[j]-a[j-1])>1){
                    flag=1;
                    break;
                }
                int temp2=a2[i];
                a2[i]=a2[a[j-1]];
                a2[a[j-1]]=temp2;
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                j--;
            }
            if(flag==1) break; 
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}