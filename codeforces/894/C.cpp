#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        ll cnt=0;
        int flag=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        //arr[i+arr[i]-1]>i
        for(ll i=0;i<n;i++){
            if(arr[i]-1>=n || arr[arr[i]-1]<=i){
                flag=1;
                // cout<<"I:"<<i<<endl;
                break;
            }
        }
        if(flag==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}