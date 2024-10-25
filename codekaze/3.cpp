#include<bits/stdc++.h>
using namespace std;

int terminalDefence(int n, int m, vector<int> &a, vector<int> &h, vector<int> &b, int k) {
    int i=0;
    while(i<n && b[i]<a[0]){
        i++;
    }
    for(int j=0;j<m;j++){
        h[j]-=k*i;
    }
    i=n-1;
    int count=0;
    while(i>=0 && b[i]>a[n-1]){
        count++;
        i--;
    }
    for(int j=0;j<m;j++){
        h[j]-=k*count;
    }
    for(int i=0;i<n;i++){
        if(h[i]!=0) return 0; 
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> a(m);
        vector<int> h(m);
        vector<int> b(n);
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>h[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        cout<<terminalDefence(n,m,a,h,b,k);
    }
    return 0;
}