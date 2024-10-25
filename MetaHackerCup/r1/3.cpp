#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;

ll mod_inverse(ll a, ll m) {
    ll res = 1;
    ll exp = m - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        exp /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream myfile2;
    myfile2.open ("3_input.txt");
    ofstream myfile;
    myfile.open ("3.txt");
    int t;
    myfile2>>t;
    for(int ti=1;ti<=t;ti++){
        ll w,g,l;
        myfile2>>w>>g>>l;
        ll res;
        if(l==0) res=(w-g)%mod;
        else{
            res=-1;
        } 
        myfile<<setprecision(10);
        myfile<<"Case #"<<ti<<": "<<res<<endl;
    }
    myfile.close();
    return 0;
}