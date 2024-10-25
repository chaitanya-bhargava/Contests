#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> & arr,int k,int i,int & n,int sum,int allowed){
    if(i==n-1){
        if(k<=allowed) return sum+k*(arr[i]);
        else return sum+allowed*(arr[i]);
    }
    int ans=0;
    for(int i=0;i<allowed;i++){
        ans+=helper(arr,k-i,i+1,n,sum+arr[i]*i,i+1);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n,k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<helper(arr,k,0,n,0,1);
    return 0;
}