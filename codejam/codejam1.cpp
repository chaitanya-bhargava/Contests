#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int x=1;
    while(x<t+1){
        vector<int> m;
        for(int i=0;i<26;i++){
            int k;
            cin>>k;
            m.push_back(k);
        }
        fflush(stdin);
        int n;
        cin>>n;
        vector<string> arr;
        for(int i=0;i<n;i++){
            string p;
            cin>>p;
            arr.push_back(p);
        }
        unordered_map<string,int> m1;
        int flag=0;
        for(int i=0;i<n;i++){
            string code;
            for(int j=0;j<arr[i].size();j++){
                code.push_back(m[arr[i][j]-'A']);
            }
            if(m1[code]==1){
                flag=1;
                break;
            }
            m1[code]=1;
        }
        if(flag==0){
            cout<<"Case #"<<x<<": NO"<<endl;
        }
        else{
            cout<<"Case #"<<x<<": YES"<<endl;
        }
        x++; 
    }
    return 0;
}