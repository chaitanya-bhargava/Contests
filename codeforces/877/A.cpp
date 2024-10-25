#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arrpos;
        vector<int> arrneg;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            if(k>0) arrpos.push_back(k);
            else if(k<0) arrneg.push_back(k);
        }
        sort(arrpos.begin(),arrpos.end());
        sort(arrneg.begin(),arrneg.end(),greater<int>());
        if(arrneg.size()>0){
            cout<<arrneg[0]<<endl;
        }
        else if(arrpos.size()>0){
            cout<<arrpos[0]<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}