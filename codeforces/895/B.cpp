#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> traps;
        for(int i=0;i<n;i++){
            int d,s;
            cin>>d>>s;
            traps.push_back({d,s});
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int forward=(traps[i].second-1)/2;
            mini=min(mini,traps[i].first+forward);
        }
        cout<<mini<<endl;
    }
    return 0;
}