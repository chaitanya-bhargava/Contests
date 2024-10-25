#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long odd=n/2;
        long long even=n/2;
        if(odd%2==0 && k%2==1){
            cout<<-1<<endl;
            continue;
        }
        else if(odd%2==1 && k%2==0){
            cout<<-1<<endl;
            continue;
        }
        else if(100000*even+99999*odd<k){
            cout<<-1<<endl;
            continue;
        }
        else if(2*even+odd>k){
            cout<<-1<<endl;
            continue;
        }
        long long remain=k-odd;
        if(remain==even){
            cout<<-1<<endl;
            continue;
        }
        cout<<"awfiawnfiuwa";
        long long sum=0;
        long long val1=remain/even;
        if(val1%2==1) val1--;
        vector<long long> ans;
        for(long long i=0;;i++){
            if((even-i)*2>remain) break;
            ans.push_back(val1);
            sum+=val1;
        }
        if(ans.size()!=0) ans.pop_back();
        while(ans.size()!=even){
            ans.push_back(2);
            sum+=2;
        }
        k-=sum;
        long long val2=k/odd;
        for(long long i=0;;i++){
            if((odd-i)>remain) break;
            ans.push_back(val2);
        }
        if(ans.size()!=0) ans.pop_back();
        while(ans.size()!=odd) ans.push_back(1);
        for(long long i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}