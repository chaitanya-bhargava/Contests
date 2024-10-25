#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> & arr,int & mid,int & t){
    int ans=0;
    int curr=0;
    for(int i=0;i<arr.size();i++){
        if(curr+arr[i]>mid){
            ans++;
            curr=0;
        }
        curr+=arr[i];
    }
    ans++;
    if(ans<=t) return true;
    return false; 
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        maxi=max(maxi,arr[i]);
    }
    int t;
    cin>>t;
    int l=maxi;
    int r=sum;
    int mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(isValid(arr,mid,t)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}