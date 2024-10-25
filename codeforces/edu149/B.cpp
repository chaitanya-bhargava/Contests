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
        int ans=0;
        int curr=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) curr++;
            else{
                ans=max(ans,curr);
                curr=1;
            }
        }
        ans=max(ans,curr);
        cout<<ans+1<<endl;
    }
    return 0;
}