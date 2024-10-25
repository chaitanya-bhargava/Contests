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
        if(s.size()%2==1){
            cout<<-1<<endl;
            continue;
        }
        int leftcount=0;
        int rightcount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') leftcount++;
            else rightcount++;
        }
        
    }
    return 0;
}