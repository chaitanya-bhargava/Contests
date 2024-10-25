#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k,h;
        cin>>n>>m>>k>>h;
        vector<int> heights(n);
        for(int i=0;i<n;i++){
            cin>>heights[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(heights[i]==h) continue;
            if(abs(h-heights[i])%k==0 && abs(h-heights[i])/k<m){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}