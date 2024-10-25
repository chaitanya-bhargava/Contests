#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> vowel(26,0);
    vowel['a'-'a']=1;
    vowel['e'-'a']=1;
    vowel['i'-'a']=1;
    vowel['o'-'a']=1;
    vowel['u'-'a']=1;
    string ans;
    int curr=0;
    for(int i=0;i<n;i++){
        if(vowel[s[i]-'a']==1){
            curr++;
        }
        else{
            if(curr==2){
                ans.push_back('$');
            }
            curr=0;
        }
        ans.push_back(s[i]);
    }
    if(curr==2) ans.push_back('$');
    cout<<ans<<endl;
    return 0;
}