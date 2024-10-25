#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int max1=n;
        int min1=-1;
        int count1=0;
        int flag=0;
        for(int i=0;i<n;i++){
            if(arr[i]==arr[0]){
                count1++;
                if(count1==k){
                    flag=1;
                    max1=i;
                }
            }
        }
        int count2=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==arr[n-1]){
                count2++;
                if(count2==k){
                    flag=1;
                    min1=i;
                }
            }
        }
        if(arr[0]==arr[n-1] && flag==1){
            cout<<"YES"<<endl;
            continue;
        }
        if(max1>min1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}