#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<t+1;i++){
        int n;
        cin>>n;
        vector<int> arr;
        vector<int> arr2;
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            arr.push_back(k);
        }
        int count=-1000000;
        unordered_map<int,int> m;
        int flag=0;
        for(int j=0;j<n;j++){
            if(m[arr[j]]<count-1){
                flag=1;
                break;
            }
            else if(m[arr[j]]==count-1){
                continue;
            } 
            else{
                m[arr[j]]=count;
                count++;
            }
        }
        if(flag==1){
            cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"Case #"<<i<<": "<<arr[0]<<" ";
        for(int j=1;j<n;j++){
            if(arr[j]!=arr[j-1]) cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}