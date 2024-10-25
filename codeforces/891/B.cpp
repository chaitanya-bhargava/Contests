#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        int c=0;
        int k=n;
        for(int i=n-1;i>=1;i--){
            if(s[i]>='5'){
                s[i]='0';
                while(s[i-1]=='9' && i>=2){
                    s[i-1]='0';
                    i--;
                }
                k=min(k,i);
                s[i-1]++;
            }
        }
        if(s[0]>='5'){
            s[0]='0';
            s="1"+s;
            k=1;
        }
        for(int i=k;i<s.size();i++){
            s[i]='0';
        }
        cout<<s<<endl;
    }
    return 0;
}