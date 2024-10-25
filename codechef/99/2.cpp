#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),greater<int> ());
        vector<long long> ans(n);
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=arr[i];
            ans[i]=sum;
        }
        for(int i=n-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}