#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') curr=0;
            else if(s[i]=='1') curr=1;
            else s[i]=curr+48;
        }
        cout<<s<<endl;
    }
    return 0;
}