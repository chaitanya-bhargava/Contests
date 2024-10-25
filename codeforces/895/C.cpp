#include<bits/stdc++.h>
using namespace std;

int factor(long long & n) {
    long long i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return i;
        }
        i += 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        long long flag=0;
        if(l==r && l>1){
            int f=factor(l);
            if(f==-1){
                cout<<-1<<endl;
                flag=1;
                continue;
            }
            else{
                cout<<l/f<<" "<<l-(l/f)<<endl;
                flag=1;
                continue;
            }
        }
        if(flag==1) continue;
        for(long long i=l;i<r+1;i++){
            if(i%2==0 && i!=2){
                cout<<i/2<<" "<<i/2<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<-1<<endl;
    }
    return 0;
}