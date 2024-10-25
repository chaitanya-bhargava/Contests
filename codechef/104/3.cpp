#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long m,n;
        cin>>n>>m;
        vector<long long> arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<long long> ans;
        ans.push_back(arr[0]);
        long long mini=arr[0];
        for(long long i=1;i<n;i++){
            if(arr[i]<mini){
                mini=arr[i];
                ans.push_back(mini);
            }
            else{
                long long k=m/arr[i];
                ans.push_back(arr[i]*k);
            }
        }
        for(long long i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}