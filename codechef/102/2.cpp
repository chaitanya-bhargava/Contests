#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        string s;
        cin>>s;
        long long ans=1;
        long long mod=1000000007;
        for(long long i=2;i<n;i+=2){
            if(s[i]=='0' && s[i-1]=='0' && s[i-2]=='0'){
                ans=(ans*3)%mod;
            }
            else if(s[i]=='0' && s[i-1]=='0' && s[i-2]=='1'){
                ans=(ans*1)%mod;
            }
            else if(s[i]=='0' && s[i-1]=='1' && s[i-2]=='0'){
                ans=(ans*1)%mod;
            }
            else if(s[i]=='0' && s[i-1]=='1' && s[i-2]=='1'){
                ans=(ans*1)%mod;
            }
            else if(s[i]=='1' && s[i-1]=='0' && s[i-2]=='0'){
                ans=(ans*0)%mod;
            }
            else if(s[i]=='1' && s[i-1]=='0' && s[i-2]=='1'){
                ans=(ans*2)%mod;
            }
            else if(s[i]=='1' && s[i-1]=='1' && s[i-2]=='0'){
                ans=(ans*2)%mod;
            }
            else if(s[i]=='1' && s[i-1]=='1' && s[i-2]=='1'){
                ans=(ans*2)%mod;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}