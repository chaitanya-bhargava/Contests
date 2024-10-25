#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,k,p;
        cin>>n>>x>>k>>p;
        if(k<x){
            p+=k*10;
            cout<<p<<endl;
        }
        else if(k<n){
            p+=x*10+(k-x)*5;
            cout<<p<<endl;
        }
        else{
            p+=x*10+(n-x)*5+20;
            cout<<p<<endl;
        }
    }
    return 0;
}