#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<string,int> count;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            count[s]++;
        }
        int ans=0;
        ans+=count["O"];
        ans+=max(count["A"],count["B"]);
        ans+=count["AB"];
        cout<<ans<<endl;
    }
    return 0;
}