#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),greater<long long> ());
        priority_queue<long long> box_xor;
        box_xor.push(arr[0]);
        for(long long i=1;i<n;i++){
            if(box_xor.top()>=arr[i]){
                int x=box_xor.top();
                box_xor.pop();
                box_xor.push(x^arr[i]);
            }
            else{
                box_xor.push(arr[i]);
            }
        }
        cout<<box_xor.size()<<endl;
    }
    return 0;
}