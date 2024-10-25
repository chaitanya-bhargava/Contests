#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<t+1;i++){
        long long n;
        cin>>n;
        n--;
        long long l=1;
        long long r=100000;
        long long mid;
        while(l<r){
            mid=(l+r)/2;
            if(((long long)26*mid*(mid-1)/2)>=n){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        long long m=(long long)26*l*(l-1)/2;
        // cout<<m<<endl;
        if(m==n) cout<<"Case #"<<i<<": A"<<endl;
        else{
            long long k=l-1;
            long long m2=(long long)m*(l-2)/l;
            long long diff=n-m2;
            char ans='A'+(diff/k);
            cout<<"Case #"<<i<<": "<<ans<<endl;
        }
    }
    return 0;
}