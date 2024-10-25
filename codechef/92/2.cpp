#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,l;
        cin>>n>>k>>l;
        if(k>n){
            cout<<-1<<endl;
            continue;
        }
        vector<vector<int>> songs;
        for(int i=0;i<n;i++){
            int m,l;
            cin>>m>>l;
            songs.push_back({m,l});
        }
        sort(songs.begin(),songs.end());
        reverse(songs.begin(),songs.end());
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(count==k) break;
            if(songs[i][1]==l){
                count++;
                ans+=songs[i][0];
            }
        }
        if(ans==0) ans--;
        cout<<ans<<endl;
    }
    return 0;
}