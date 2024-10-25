#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        for(long long i=0;i<n;i++){
            long long s=arr[i];
            long long ans=0;
            for(long long i=0;i<n;i++){
                ans+=(abs(s-arr[i])+1);
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}