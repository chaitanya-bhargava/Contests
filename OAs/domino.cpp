#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> & A,int ind,int last,vector<vector<int>> & dp){
    if(ind==A.size()-2){
        if(A[ind]==last || last==0) return dp[ind][last]=1;
        else return dp[ind][last]= 0;
    }
    if(dp[ind][last]!=-1) return dp[ind][last];
    int pick=0;
    if(A[ind]==last || last==0) pick=1+helper(A,ind+2,A[ind+1], dp);
    int not_pick=helper(A,ind+2,last, dp);
    return dp[ind][last]=max(pick,not_pick);
}

int solution(vector<int> & A){
    vector<vector<int>> dp(A.size(),vector<int> (7,-1));
    int ans=(A.size()/2)-helper(A,0,0,dp);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<solution(A);
    return 0;
}