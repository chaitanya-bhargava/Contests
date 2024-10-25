#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if((n/k)<2){
            cout<<"NO"<<endl;
            continue;
        }
        int p=k*2;
        int oddcount=(n-p+1)/2;
        if(oddcount%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}