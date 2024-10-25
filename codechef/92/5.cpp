#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> candies(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>candies[i];
            sum+=candies[i];
        }
        if(sum<k){
            cout<<0<<endl;
            continue;
        }
        
    }
    return 0;
}