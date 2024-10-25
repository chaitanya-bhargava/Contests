#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream myfile2;
    myfile2.open ("line_of_delivery_part_1_input.txt");
    ofstream myfile;
    myfile.open ("line_of_delivery_part_1_output.txt");
    int t;
    myfile2>>t;
    for(int ti=1;ti<=t;ti++){
        ll n,g;
        myfile2>>n>>g;
        ll ans=INT_MAX;
        for(int i=0;i<n;i++){
            ll s;
            myfile2>>s;
            ans=min(ans,abs(g-s));
        }
        myfile<<"Case #"<<ti<<": "<<ans<<endl;
    }
    myfile.close();
    return 0;
}