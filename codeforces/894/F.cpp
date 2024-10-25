#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long double w,f;
        cin>>w>>f;
        if(f>w){
            long double temp=w;
            w=f;
            f=temp;
        }
        long double n;
        cin>>n;
        vector<long double> a(n);
        for(long double i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end(),greater<long double>());
        vector<long double> pre(n);
        pre[0]=a[0];
        // cout<<pre[0]<<" ";
        for(long double i=1;i<n;i++){
            pre[i]=a[i]+pre[i-1];
            // cout<<pre[i]<<" ";
        }
        long double ans=1;
        long double i=0;
        long double curr=0;
        while(i<n){
            // cout<<pre[i]<<" "<<curr<<" "<<w<<" "<<f<<endl;
            if(pre[i]-curr<w) i++;
            else{
                long double x=ceil((pre[i]-curr)/w);
                // cout<<x<<endl;
                w=w*x-pre[i];
                f=f*x;
                if(f>w){
                    long double temp=w;
                    w=f;
                    f=temp;
                }
                ans+=x-1;
                curr=pre[i];
                i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}