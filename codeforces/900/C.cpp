#include<bits/stdc++.h>
using namespace std;

#define ll long double 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        ll x;
        cin>>n>>k>>x;
        cout<<n<<" "<<k<<" "<<x<<endl;
        ll maxx=n*(n+1)/2;
        if(x>maxx){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}