#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        k=min(n,k);
        long long ans=1;
        for(long long i=k;i>1;i--){
            ans=(i*ans)%1000000007;
        }
        cout<<ans<<endl;
    }
    return 0;
}