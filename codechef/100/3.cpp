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
        int flag=0;
        int ind=-1;
        for(int i=0;i<n-2;i++){
            if(s[i]=='1'){
                flag=1;
                ind=i;
                break;
            }
        }
        if(flag==0){
            cout<<s<<endl;
            continue;
        }
        string ans;
        for(int i=0;i<n;i++){
            ans.push_back('0');
        }
        ans[ind]='1';
        cout<<ans<<endl;
    }
    return 0;
}