#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n+1);
        for(int i=1;i<n+1;i++){
            cin>>arr[i].first;
            arr[i].second=i;
        }
        sort(arr.begin(),arr.end());
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int c,k;
            cin>>c>>k;
            vector<int> broken(n+1,0);
            for(int i=0;i<k;i++){
                int num;
                cin>>num;
                broken[num]=1;
            }
            int sum=0;
            int ind=1;
            int ans=0;
            while(ind<n+1){
                if(broken[arr[ind].second]==0){
                    if(sum+arr[ind].first<=c){
                        sum+=arr[ind].first;
                        ans++;
                    }
                    else{
                        break;
                    }
                }
                ind++;
            }
            cout<<ans<<" ";
            broken={0};
        }
    }
    return 0;
}