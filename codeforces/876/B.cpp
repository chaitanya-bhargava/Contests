#include<bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(vector<long long> & a,vector<long long> & b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
};

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        priority_queue<vector<long long>,vector<vector<long long>>,Compare> param; 
        for(long long i=0;i<n;i++){
            long long p,q;
            cin>>p>>q;
            param.push({p,q});
        }
        long long ans=0;
        vector<long long> on;
        long long broken_lim=0;
        while(!param.empty()){
            long long a=param.top()[0];
            long long b=param.top()[1];
            param.pop();
            if(a<=broken_lim){
                continue;
            }
            ans+=b;
            on.push_back(a);
            broken_lim=on.size();
            long long i=0;
            while(i<on.size() && on[i]<=broken_lim){
                i++;
            }
            if(i==on.size()) on.clear();
            else on.erase(on.begin(),on.begin()+i);
            // cout<<"A:"<<a<<" B:"<<b<<" On:"<<on.size()<<" Broken_lim:"<<broken_lim<<" ans:"<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}