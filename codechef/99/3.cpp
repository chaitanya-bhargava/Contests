#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int sum=0;
        for(int i=0;i<3;i++){
            sum+=arr[i];
        }
        int i=0;
        int j=2;
        vector<vector<int>> intervals;
        while(j<n){
            if(sum%3!=0){
                intervals.push_back({i,j,3-sum%3});
            }
            sum-=arr[i];
            i++;
            j++;
            if(j>=n) break;
            sum+=arr[j];
        }
        for(int i=0;i<intervals.size();i++){
            cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<","<<intervals[i][2]<<"],";
        }
        cout<<endl;
        if(intervals.size()==0){
            cout<<0<<endl;
            continue;
        } 
        int ans=intervals[0][2];
        int prev=intervals[0][1];
        int inc=intervals[0][2];
        for(int i=1;i<intervals.size();i++){
            cout<<i<<" "<<ans<<" "<<prev<<" "<<inc<<endl;
            if(intervals[i][0]<=prev){
                if(intervals[i][2]<=inc){
                    intervals.erase(intervals.begin()+i);
                }
                else{
                    intervals[i][2]-=inc;
                    ans+=intervals[i][2];
                    prev=intervals[i][1];
                    inc=intervals[i][1];
                }
            }
            else{
                ans+=intervals[i][2];
                prev=intervals[i][1];
                inc=intervals[i][2];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}