#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> & A,int B){
    unordered_map<int,int> mp;
    for(int i=0;i<A.size();i++){
        mp[A[i]]++;
    }
    vector<int> vec;
    for(auto it:mp){
        vec.push_back(it.second);
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int sum=0;
    for(int i=0;i<B;i++){
        sum+=vec[i];
    }
    if(sum>=A.size()) return 0;
    return A.size()-sum;
}

int main() {
    int n;
    cin>>n;
    int B;
    cin>>B;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<solve(A,B)<<endl;
    return 0;
}
