#include<bits/stdc++.h>
using namespace std;

int xAndY(int x, int y, vector<int> &a)
{
    int ans=INT_MAX;
    for(int i=0;i<a.size();i++){
        if(a[i]>=x && a[i]<=y && a[i]<ans){
            ans=a[i];
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<xAndY(x,y,a)<<endl;
    }
    return 0;
}