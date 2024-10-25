#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream myfile;
    myfile.open ("line_by_line_output.txt");
    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        long double n,p;
        cin>>n>>p;
        long double p2=pow(pow(p/100,n-1),(long double)1.0/n)*100;
        cout<<p2<<endl;
        myfile<<setprecision(10);
        myfile<<"Case #"<<ti<<": "<<p2-p<<endl;
    }
    myfile.close();
    return 0;
}