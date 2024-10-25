#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<t+1;i++){
        int m,r,n;
        cin>>m>>r>>n;
        vector<int> lights;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            lights.push_back(k);
        }
        int curr=0;
        int pt=-1;
        int ans=0;
        int flag=0;
        while(pt<lights.size()){
            cout<<curr<<lights[pt]<<endl;
            int oldpt=pt;
            while(curr+r>=lights[pt]){
                pt++;
            }
            pt--;
            if(pt==oldpt) break;
            curr=lights[pt]+r;
            ans++;
            if(curr>=m) break;
        }
        if(flag==0) cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
        else cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}