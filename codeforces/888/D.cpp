#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n-1);
        for(long long i=0;i<n-1;i++){
            cin>>arr[i];
        }
        unordered_map<long long,long long> count;
        count[arr[0]]++;
        vector<long long> arr2(n-1);
        arr2[0]=arr[0];
        for(long long i=1;i<n-1;i++){
            arr2[i]=arr[i]-arr[i-1];
            count[arr2[i]]++;
        }
        // for(long long i=0;i<n-1;i++){
        //     cout<<arr2[i]<<" ";
        // }
        // cout<<endl;
        long long sum_extra=0;
        long long sum_missing=0;
        long long count_extra=0;
        long long count_missing=0;
        for(auto it:count){
            if(it.first<=n && it.second>1){
                sum_extra+=it.first*(it.second-1);
                count_extra+=it.second-1;
            }
            else if(it.first>n && it.second!=0){
                sum_extra+=it.first*(it.second);
                count_extra+=it.second;
            }
        }
        for(long long i=1;i<n+1;i++){
            if(count[i]==0){
                count_missing++;
                sum_missing+=i;
            }
        }
        // cout<<count_extra<<" "<<count_missing<<" "<<sum_extra<<" "<<sum_missing<<endl;
        if((sum_extra==sum_missing && 2*count_extra==count_missing) || (count_extra==0 && count_missing==1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}