#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> b;
        int maxi=INT_MIN;
        int m=n*(n-1)/2;
        for(int i=0;i<m;i++){
            int k;
            cin>>k;
            maxi=max(maxi,k);
            b.insert(k);
        }
        vector<int> arr(b.begin(),b.end());
        int diff=n-arr.size();
        for(int i=0;i<diff;i++){
            arr.push_back(maxi);
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}