#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int x=a-b+c-d;
        if(x<0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}