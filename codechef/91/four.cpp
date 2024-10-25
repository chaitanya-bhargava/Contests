#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),greater<int>());
        vector<int> prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=arr[i]+prefix[i-1];
        }
        int x=0;
        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            x+=prefix[r-l];
        }
        cout<<x<<endl;
    }
    return 0;
}