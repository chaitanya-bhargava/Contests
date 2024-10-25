#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        float diff=abs(a-b);
        diff=(float)diff/2;
        int ans=ceil((float)diff/c);
        cout<<ans<<endl;
    }
    return 0;
}