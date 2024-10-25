#include<bits/stdc++.h>
using namespace std;

//x(x-1)>=2*n
//x2-x-2n=0

//1+root(1+8n)/2

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long x=(long long)(1+sqrt(1+8*n))/2;
        long long curr=(long long)x*(x-1)/2;
        cout<<x+n-curr<<endl;
    }
    return 0;
}