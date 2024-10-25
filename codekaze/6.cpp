#include<bits/stdc++.h>
using namespace std;

long long maxiAnd(int n,vector<int> &a){
    sort(a.begin(),a.end());
    long long k=log2(a[0])+1;
    long long ans=pow(2,k)-1;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<maxiAnd(n,a)<<endl;
    }
    return 0;
}