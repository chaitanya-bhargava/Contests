#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m,d;
        cin>>n>>m>>d;
        vector<ll> a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll prev=-1;
        ll ans=0;
        ll count=0;
        for(ll i=0;i<n && count<m;i++){
            if(a[i]-d*(i-prev)>0){
                ans+=a[i]-d*(i-prev);
                prev=i;
                count++;
            }
            // cout<<ans<<" ";
        }
        // cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}