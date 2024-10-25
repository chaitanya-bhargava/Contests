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
        sort(arr.begin(),arr.end());
        vector<int> ans(n);
        int j=0;
        for(int i=0;i*2<n;i++){
            ans[j]=arr[i];
            j+=2;
        }
        j=1;
        for(int i=n/2+1;i<n;i++){
            ans[j]=arr[i];
            j+=2;
        }
        int flag=0;
        for(int i=1;i<n-1;i++){
            if(i%2==0){
                if(ans[i]>=ans[i-1] || ans[i]>=ans[i+1]){
                    flag=1;
                    break;
                }
            }
            else{
                if(ans[i]<=ans[i-1] || ans[i]<=ans[i+1]) {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}