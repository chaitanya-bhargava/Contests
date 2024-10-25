#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        int flag=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==k) flag=1;
        }
        if(flag==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}