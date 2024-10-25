#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
long long getNcR(int n, int r)
{
 
    long long p = 1, k = 1;

    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
 
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 

    }
 
    else
        p = 1;
    return p;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        map<int,int,greater<int>>freq;
        for(auto it:mp){
            freq[it.second]++;
        }
        long long res=1;
        auto iter=freq.begin();
        while(k>0){

            if(k>iter->second){
                k=k-iter->second;
                int tempct=iter->second;
                while(tempct--){
                    res=(res*(iter->first))%mod;

                }
            }
            else{
                int n1=iter->second;
                long long pnc=getNcR(n1,k);
                res=(res*pnc)%mod;
                while(k>0){
                    res=(res*((long long)(iter->first)))%mod;
                    k--;
                }
                
                break;
            }
            iter++;
        }
        cout<<res<<endl;
    
    }
}