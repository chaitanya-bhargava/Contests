#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> & A){
    vector<int> mp(10,0);
    int n=A.size();
    for(int i=0;i<n;i++){
        int k=A[i];
        int p=k%10;
        k=k/10;
        int q=k%10;
        if(p==q) mp[p]++;
        else{
            mp[p]++;
            mp[q]++;
        }
    }
    int ans=-1;
    for(for(int)){
        cout<<it<<" ";
    }
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