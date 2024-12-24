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
 
ofstream sso("output.txt");

bool valid(ll A,int ind,vector<ll> & inst){
    ll i=0;
    ll n=inst.size();
    ll B=0;
    ll C=0;
    sso<<endl;
    sso<<A<<":"<<endl;
    while(i<n){
        ll temp=inst[i+1];
        ll op;
        if(temp<=3) op=temp;
        else if(temp==4) op=A;
        else if(temp==5) op=B;
        else if(temp==6) op=C;
        switch (inst[i])
        {
        case 0:
            A=A/(pow(2,op));
            i+=2;
            break;
        case 1:
            B=B^temp;
            i+=2;
            break;
        case 2:
            B=op%8;
            i+=2;
            break;
        case 3:
            if(A!=0){
                i=temp;
            }
            else i+=2;
            break;
        case 4:
            B=B^C;
            i+=2;
            break;
        case 5:
            sso<<op%8<<",";
            if((op%8)!=inst[ind]) return false;
            else ind++;
            i+=2;
            break;
        case 6:
            B=A/(pow(2,op));
            i+=2;
            break;
        case 7:
            C=A/(pow(2,op));
            i+=2;
            break;
        default:
            break;
        }
    }
    return true;
}

bool helper(ll A,int i,vector<ll> & inst){
    if(i==-1) {
        cout<<A<<endl;
        return true;
    }
    for(int j=0;j<8;j++){
        ll temp=(A*8)+j;
        if(valid(temp,i,inst)){
            if(helper(temp,i-1,inst)) return true;
        }
    }
    return false;
}

// A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> lines;
//     fstream ss("input.txt");
//     ofstream sso("output.txt");
//     string line;
//     while(getline(ss,line)){
//         lines.push_back(line);
//     }
//     ll A=stoi(lines[0].substr(lines[0].find(": ")+2));
//     ll B=stoi(lines[1].substr(lines[1].find(": ")+2));
//     ll C=stoi(lines[2].substr(lines[2].find(": ")+2));
//     string program=lines[4].substr(lines[4].find(": ")+2);
//     vector<ll> inst;
//     stringstream ss2(program);
//     string num;
//     while(getline(ss2,num,',')){
//         inst.push_back(stoi(num));
//     }
//     ll i=0;
//     ll n=inst.size();
//     while(i<n){
//         ll temp=inst[i+1];
//         ll op;
//         if(temp<=3) op=temp;
//         else if(temp==4) op=A;
//         else if(temp==5) op=B;
//         else if(temp==6) op=C;
//         switch (inst[i])
//         {
//         case 0:
//             A=A/(pow(2,op));
//             i+=2;
//             break;
//         case 1:
//             B=B^temp;
//             i+=2;
//             break;
//         case 2:
//             B=op%8;
//             i+=2;
//             break;
//         case 3:
//             if(A!=0){
//                 i=temp;
//             }
//             else i+=2;
//             break;
//         case 4:
//             B=B^C;
//             i+=2;
//             break;
//         case 5:
//             cout<<op%8<<",";
//             i+=2;
//             break;
//         case 6:
//             B=A/(pow(2,op));
//             i+=2;
//             break;
//         case 7:
//             C=A/(pow(2,op));
//             i+=2;
//             break;
//         default:
//             break;
//         }
//     }
//     return 0;
// }

// B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> lines;
    fstream ss("input.txt");
    ofstream sso("output.txt");
    string line;
    while(getline(ss,line)){
        lines.push_back(line);
    }
    ll A=stoi(lines[0].substr(lines[0].find(": ")+2));
    ll B=stoi(lines[1].substr(lines[1].find(": ")+2));
    ll C=stoi(lines[2].substr(lines[2].find(": ")+2));
    string program=lines[4].substr(lines[4].find(": ")+2);
    vector<ll> inst;
    stringstream ss2(program);
    string num;
    while(getline(ss2,num,',')){
        inst.push_back(stoi(num));
    }
    ll n=inst.size();
    helper(0,n-1,inst);
    return 0;
}