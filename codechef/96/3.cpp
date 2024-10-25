#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<long long> q(m);
        long long sum=0;
        for(long long i=0;i<m;i++){
            cin>>q[i];
            sum+=q[i];
        }
        long long tot=(long long)(n*(n+1)/2);
        cout<<(tot-sum)<<endl;
        // int i=0;
        // int j=0;
        // int ans=0;
        // while(i<n && j<m){
        //     if(i==q[j]){
        //         i++;
        //         j++;
        //     }
        //     else{

        //     }
        // }
    }
    return 0;
}