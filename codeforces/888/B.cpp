#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> even;
        vector<int> pos(n,0);
        vector<int> odd;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==0){
                even.push_back(arr[i]); 
                pos[i]=1;
            } 
            else odd.push_back(arr[i]); 
        }
        if(even.size()==0 || odd.size()==0){
            cout<<"YES"<<endl;
            continue;
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int o=0;
        int e=0;
        for(int i=0;i<n;i++){
            if(pos[i]==0){
                arr[i]=odd[o];
                o++;
            }
            else{
                arr[i]=even[e];
                e++;
            }
        }
        int flag=0;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}