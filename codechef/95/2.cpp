#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m,h;
        cin>>n>>m>>h;
        vector<long long> cap(n);
        for(long long i=0;i<n;i++){
            cin>>cap[i];
        }
        vector<long long> power(m);
        for(long long i=0;i<m;i++){
            cin>>power[i];
        }
        sort(power.begin(),power.end(),greater<long long>());
        sort(cap.begin(),cap.end(),greater<long long>());
        long long ans=0;
        for(long long i=0,j=0;i<n,j<m;i++,j++){
            ans+=min(power[j]*h,cap[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}