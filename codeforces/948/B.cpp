#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define V vector
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define eb emplace_back
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define fi first
#define se second
#define _F(i, a, b) for (int i = a; i <= b; i++)
#define _FR(i, a, b) for (int i = a; i >= b; i--)
#define IF(a,b,c) ((a)?(b):(c));
#define _sort(x) sort((x).begin(),(x).end());
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const ll infl = 0x3f3f3f3f3f3f3f3fll;
 
void decToBinary(int n,vector<string> & bin)
{
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            bin.push_back("1");
        else
            bin.push_back("0");
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> bin;
        decToBinary(n,bin);
        for(int i=0;i<32;i++){
            int flag=0;
            for(int i=1;i<32;i++){
                if(bin[i]=="1" && bin[i-1]=="1"){
                    bin[i-2]="1";
                    bin[i-1]="0";
                    bin[i]="-1";
                    flag=1;
                }
                else if(bin[i]=="1" && bin[i-1]=="-1"){
                    bin[i-1]="0";
                    bin[i]="-1";
                    flag=1;
                }
                else if(bin[i]=="-1" && bin[i-1]=="1"){
                    bin[i-1]="0";
                    bin[i]="1";
                    flag=1;
                    flag=1;
                }
                else if(bin[i]=="-1" && bin[i-1]=="-1"){
                    bin[i-2]="-1";
                    flag=1;
                    bin[i-1]="0";
                    bin[i]="1";
                }
            }
            if(flag==0) break;
        }
        reverse(bin.begin(),bin.end());
        cout<<"32"<<endl;
        for(int i=0;i<32;i++){
            cout<<bin[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}