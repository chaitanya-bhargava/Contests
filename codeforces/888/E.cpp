#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> costs(n+1);
        for(int i=1;i<n+1;i++){
            cin>>costs[i];
        }
        unordered_map<int,int> unlimited;
        unordered_map<int,int> make_not_buy;
        for(int i=0;i<k;i++){
            int p;
            cin>>p;
            unlimited[p]=1;
        }
        for(int i=1;i<n+1;i++){
            int m;
            cin>>m;
            if(unlimited[i]==1){
                continue;
            }
            
        }
    }
    return 0;
}