#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int> mp;
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            if(mp[k]==0){
                count++;
                mp[k]=1;
            } 
            else if(mp[k]==1) {
                count--;
                mp[k]=0;
            }
            ans=max(count,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}