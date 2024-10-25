#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool prime[10000001];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= 10000000; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 10000000; i += p)
                prime[i] = false;
        }
    }
}

int res[10000001];
void precompute(){
    res[1]=0;
    res[2]=0;
    res[3]=0;
    res[4]=0;
    res[5]=2;
    for(int i=6;i<=10000000;i++){
        if(prime[i] && prime[i-2]){
            res[i]=res[i-1]+1;
        }
        else{
            res[i]=res[i-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream myfile2;
    myfile2.open ("2_input.txt");
    ofstream myfile;
    myfile.open ("2.txt");
    SieveOfEratosthenes();
    precompute();
    int t;
    myfile2>>t;
    for(int ti=1;ti<=t;ti++){
        ll n;
        myfile2>>n;
        myfile<<setprecision(10);
        myfile<<"Case #"<<ti<<": "<<res[n]<<endl;
    }
    myfile.close();
    return 0;
}