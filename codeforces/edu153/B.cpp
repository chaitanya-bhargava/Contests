#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long m,k,a1,ak;
        cin>>m>>k>>a1>>ak;
        long long temp=m;
        long long num=m/k;
        num=min(num,ak);
        m-=num*k;
        if(m-a1<=0){
            cout<<0<<endl;
            continue;
        }
        else{
            long long num_of_ak=temp/k;
            num_of_ak-=ak;
            temp-=ak*k;
            long long mini=m;
            for(long long i=0;i<num_of_ak+1;i++){
                long long temp2=temp;
                temp2-=i*k;
                long long count=0;
                count+=i;
                if(temp2>a1) count+=temp2-a1;
                mini=min(mini,count);
            }
            cout<<mini<<endl;
        }
    }
    return 0;
}