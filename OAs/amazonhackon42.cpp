#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    s[n-1]='c';
    int ans=0;
    int i=0;
    int j=n-1;
    while(i<j){
        if(s[j]!=s[i]){
            ans++;
            j--;
        }
        else{
            i++;
            j--;
        }
    }
    cout<<ans<<endl;
    return 0;
}