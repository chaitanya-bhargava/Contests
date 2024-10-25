#include <bits/stdc++.h>
using namespace std;
 
int helper(vector<int> & a,vector<int> & b,int curr,int i,int & k,int maxind){
    if(curr==k){
        return 0;
    }
    if(i>a.size()){
        return b[maxind]*(curr-k-1);
    }
    int same=INT_MIN; 
    if(i!=0){
        same=b[maxind]+helper(a,b,curr+1,i,k,maxind);
    }
    if(b[i]>b[maxind]){
        maxind=i;
    }
    int next=a[i]+helper(a,b,curr+1,i+1,k,maxind);
    return max(same,next);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        cout<<helper(a,b,0,0,k,0)<<endl;
    }
    return 0;
}