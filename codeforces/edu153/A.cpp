#include<bits/stdc++.h>
using namespace std;

bool isValid(string & t,string & s){
    int n=t.size();
    int m=s.size();
    for(int i=0;i<n;i++){
        if(t.substr(i,m)==s) return false;
    }
    return true;
}

void solve(int cnt1,int cnt2,int & n,vector<string> &ans,string &op,int ind,string & s)
{
    if(ind>=n*2)
    {
        if(isValid(op,s))
        ans.push_back(op);
        return;
        }
    if(cnt1<n and ind<n*2-1)
    {
        op+='(';
        solve(cnt1+1,cnt2,n,ans,op,ind+1,s);
        if(ans.size()==1) return;
        op.pop_back();
    }
    
    if(cnt2<cnt1 and ind>0)
    {
        op+=')';
        solve(cnt1,cnt2+1,n,ans,op,ind+1,s);
        if(ans.size()==1) return;
        op.pop_back();
    }
    
}


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        string op="";
        vector<string> ans;
        solve(0,0,n,ans,op,0,s);
        if(ans.size()==1){
            cout<<"YES"<<endl;
            cout<<ans[0]<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}