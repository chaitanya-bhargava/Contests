#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        if(x<k){
            cout<<1<<endl<<x<<endl;
            continue;
        }
        if(x%k!=0){
            cout<<1<<endl<<x<<endl;
            continue;
        }
        cout<<2<<endl;
        for(int i=1;i<x+1;i++){
            if(i%k!=0 && (x-i)%k!=0){
                cout<<i<<" "<<x-i<<endl;
                break;
            }
        }
    }
    return 0;
}