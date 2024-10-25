#include<bits/stdc++.h>
using namespace std;

vector<int> binaryQueries(int n, vector<int> &a, int q, vector<vector<int>> &queries) {
    vector<int> res;
    for(int i=0;i<q;i++){
        int l=queries[i][0];
        int r=queries[i][1];
        int x=queries[i][2];
        a[l]=a[l]^x;
        long long ans=a[l];
        for(int j=l+1;j<r+1;j++){
            a[j]=a[j]^x;
            ans=ans | a[j];
        }
        res.push_back(ans);
    }
    return res;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<vector<int>> queries;
        for(int i=0;i<q;i++){
            int l,r,x;
            cin>>l>>r>>x;
            queries.push_back({l,r,x});
        }
        vector<int> ans=binaryQueries(n,a,q,queries);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}