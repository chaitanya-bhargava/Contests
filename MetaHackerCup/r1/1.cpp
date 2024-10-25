#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream myfile2;
    myfile2.open ("1_input.txt");
    ofstream myfile;
    myfile.open ("1.txt");
    int t;
    myfile2>>t;
    for(int ti=1;ti<=t;ti++){
        ll n;
        myfile2>>n;
        vector<pair<ll,ll>> arr(n);
        for(ll i=0;i<n;i++){
            myfile2>>arr[i].first>>arr[i].second;
        }
        long double ans=0;
        for(ll i=n-1;i>=0;i--){
            ans=max(ans,(long double)(i+1)/arr[i].second);
        }
        int flag=0;
        for(ll i=0;i<n;i++){
            long double t=ans/(i+1);
            t=1/t;
            if(t<arr[i].first || t>arr[i].second){
                flag=1;
                break;
            }
        }
        myfile<<setprecision(10);
        if(flag==0) myfile<<"Case #"<<ti<<": "<<ans<<endl;
        else myfile<<"Case #"<<ti<<": "<<-1<<endl;
    }
    myfile.close();
    return 0;
}