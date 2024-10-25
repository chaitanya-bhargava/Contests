#include<bits/stdc++.h>
using namespace std;

bool helper(string & target,string curr,int col,int ind,int & n,int & m,vector<string> & arr,map<pair<string,int>,int> & memo){
    if(col==m || curr.size()==target.size()){
        return target==curr;
    }
    if(memo[{curr,col}]!=0){
        if(memo[{curr,col}]==1) return true;
        else return false;
    }
    for(int i=0;i<n;i++){
        if(arr[i][col]==target[ind]){
            curr.push_back(arr[i][col]);
            if(helper(target,curr,col+1,ind+1,n,m,arr,memo)){
                memo[{curr,col}]=1;
                return true;
            }
            curr.pop_back();
        }
        if(helper(target,curr,col+1,ind,n,m,arr,memo)){
            memo[{curr,col}]=1;
            return true;
        }
    }
    memo[{curr,col}]=-1;
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        string target="vika";
        map<pair<string,int>,int> memo;
        if(helper(target,"",0,0,n,m,arr,memo)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}