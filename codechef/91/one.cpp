#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int server=0;
        int alice=0;
        int bob=0;
        for(int i=0;i<s.size();i++){
            if(server==0){
                if(s[i]=='A') alice++;
                else{
                    server=1;
                } 
            }
            else{
                if(s[i]=='B') bob++;
                else{
                    server=0;
                } 
            }
        }
        cout<<alice<<" "<<bob<<endl;
    }
    return 0;
}