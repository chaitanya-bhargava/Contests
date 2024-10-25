#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n,0);
        int ans=0;
        for(int i=0;i<(n+1)/2;i+=k){
            arr[i]=1;
            arr[n-i-1]=1;
            ans+=2;
            if(i==n-i-1)ans--;
        }
        int curr=0;
        for(int i=1;i<n;i++){
            if(arr[i]==1){
                curr=0;
                continue;
            }
            curr++;
            if(curr==k){
                arr[i]=1;
                ans++;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}