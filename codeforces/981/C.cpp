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
        vector<int> a(n+2);
        a[0]=-1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        a[n+1]=-1;
        // for(int i=0;i<n+2;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        int i=1;
        int j=n;
        while(i<j){
            if(a[i]==a[j]){
                i++;
                j--;
            }
            else{
                int no_swap=0;
                if(a[i]==a[i-1]) no_swap++;
                if(a[i]==a[i+1]) no_swap++;
                if(a[j]==a[j-1]) no_swap++;
                if(a[j]==a[j+1]) no_swap++;
                int swap=0;
                if(a[i]==a[j-1]) swap++;
                if(a[i]==a[j+1]) swap++;
                if(a[j]==a[i-1]) swap++;
                if(a[j]==a[i+1]) swap++;
                if(swap<no_swap){
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
                i++;
                j--;
            }
        }
        i=1;
        j=n;
        while(i<j){
            if(a[i]==a[j]){
                i++;
                j--;
            }
            else{
                int no_swap=0;
                if(a[i]==a[i-1]) no_swap++;
                if(a[i]==a[i+1]) no_swap++;
                if(a[j]==a[j-1]) no_swap++;
                if(a[j]==a[j+1]) no_swap++;
                int swap=0;
                if(a[i]==a[j-1]) swap++;
                if(a[i]==a[j+1]) swap++;
                if(a[j]==a[i-1]) swap++;
                if(a[j]==a[i+1]) swap++;
                if(swap<no_swap){
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
                i++;
                j--;
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        int ans=0;
        for(int i=1;i<n;i++){
            if(a[i]==a[i+1]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}