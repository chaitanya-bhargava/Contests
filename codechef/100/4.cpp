#include<bits/stdc++.h>

using namespace std;

vector<bool> createSieve(int n){
    vector<bool> sieve(n,true);
    sieve[0]=true;
    sieve[1]=true;
    for(int i=2;i*i<n;i++){
        if(sieve[i]){
            for(int j=i*i;j<n;j+=i){
                sieve[j]=false;
            }
        }
    }
    return sieve;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<bool> primes=createSieve(n);
        int flag=0;
        int ind=-1;
        for(int i=2;i<n/2+1;i++){
            if(primes[i] && primes[n-i]){
                ind=i;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans(n);
        int count=1;
        for(int i=ind;count<(n+1);i=(i+1)%n){
            ans[i]=count;
            count++;
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}