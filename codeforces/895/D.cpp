#include<bits/stdc++.h>
using namespace std;

long long first_sum(long long & n){
    return (n*(n+1))/2;
}

long long last_sum(long long & n,long long & m){
    long long diff=n-m;
    return first_sum(n)-first_sum(diff);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long n,x,y;
        cin>>n>>x>>y;
        long long x_num=n/x;
        long long y_num=n/y;
        long long common;
        long long k=(x / __gcd(x, y)) * y;
        common=n/k;
        long long ans=0;
        long long n1=x_num-common;
        long long n2=y_num-common;
        ans+=last_sum(n,n1);
        ans-=first_sum(n2);
        cout<<ans<<endl;
    }
    return 0;
}