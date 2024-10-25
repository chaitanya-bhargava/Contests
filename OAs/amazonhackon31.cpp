#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string og=s;
    while(s.size()>1){
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=s[i]-'0';
        }
        s=to_string(sum);
    }
    long long ans=stoll(s)*stoll(og);
    cout<<ans<<endl;
    return 0;
}