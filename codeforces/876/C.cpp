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
        if(arr[n-1]==1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        vector<int> ans;
        int num1=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==0) ans.push_back(0);
            else{
                num1++;
                if(i-1>=0 && arr[i-1]==1){
                    ans.push_back(0);
                }
                else {
                    ans.push_back(num1);
                    num1=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}