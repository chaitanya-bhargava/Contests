#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream myfile;
    myfile.open ("walk_the_line_output.txt");
    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        ll n,k;
        cin>>n>>k;
        ll mini=INT_MAX;
        for(int i=0;i<n;i++){
            ll s;
            cin>>s;
            mini=min(mini,s);
        }
        if(n==1){
            if(mini<=k){
                myfile<<"Case #"<<ti<<": YES"<<endl;
            }
            else myfile<<"Case #"<<ti<<": NO"<<endl;
        }
        else{
            if((mini*(n-2)*2+mini)<=k){
                myfile<<"Case #"<<ti<<": YES"<<endl;
            }
            else myfile<<"Case #"<<ti<<": NO"<<endl;
        }
    }
    myfile.close();
    return 0;
}