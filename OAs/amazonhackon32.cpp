#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        s.insert(k);
    }
    double ans=0;
    for(auto it:s){
        ans+=pow(2,it);
    }
    cout<<ans<<endl;
    return 0;
}