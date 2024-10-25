#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        long long sum=0;
        long long l=0;
        long long r=n-1;
        while(l<r && arr[l+1]>arr[l]){
            sum+=arr[l];
            l++;
        }
        while(l<r && arr[r-1]>arr[r]){
            sum+=arr[r];
            r--;
        }
        sum+=(r-l+1)*min(arr[l],arr[r]);
        sum+=abs(arr[l]-arr[r]);
        cout<<sum<<endl;
    }
    return 0;
}