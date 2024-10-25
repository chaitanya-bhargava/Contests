#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }
    if(n%2==0){
        cout<<"First"<<endl;
        int maxx=INT_MIN;
        int ind=-1;
        for(int i=1;i<n+1;i++){
            if(arr[i]>maxx){
                ind=i;
                maxx=arr[i];
            }
        }
        cout<<ind<<endl;
        fflush(stdout);
        while(true){
            int j;
            cin>>j;
            if(j<=0){
                return 0;
            }
            int d=min(arr[ind],arr[j]);
            arr[ind]-=d;
            arr[j]-=d;
            int maxx=INT_MIN;
            ind=-1;
            for(int i=1;i<n+1;i++){
                if(arr[i]>maxx){
                    ind=i;
                    maxx=arr[i];
                }
            }
            cout<<ind<<endl;
            fflush(stdout);
        }
    }
    else{
        cout<<"Second"<<endl;
        fflush(stdout);
        while(true){
            int i;
            cin>>i;
            if(i<=0){
                return 0;
            }
            int maxx=INT_MIN;
            int ind=-1;
            for(int k=0;k<n;k++){
                if(arr[k]>maxx && k!=i){
                    ind=k;
                    maxx=arr[k];
                }
            }
            cout<<ind<<endl;
            fflush(stdout);
            int d=min(arr[i],arr[ind]);
            arr[ind]-=d;
            arr[i]-=d;
        }
    }
    return 0;
}