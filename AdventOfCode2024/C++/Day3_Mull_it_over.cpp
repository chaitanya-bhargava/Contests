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
 
long long parse(string & s,int & start){
    int i=start+4;
    string a;
    while(i<s.size() && isdigit(s[i])){
        a.push_back(s[i]);
        i++;
    }
    if(s[i]!=',') return 0;
    i++;
    string b;
    while(i<s.size() && isdigit(s[i])){
        b.push_back(s[i]);
        i++;
    }
    if(s[i]!=')') return 0;
    return stoll(a)*stoll(b);
}



// A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string complete;
    string word;
    fstream ss("day_3_input.txt");
    while(ss>>word){
        complete+=" "+word;
    }
    long long res=0;
    
    int mul_ind=complete.find("mul(");
    while(mul_ind!=string::npos){
        res+=parse(complete,mul_ind);
        mul_ind=complete.find("mul(",mul_ind+1);
    }
    cout<<res<<endl;
    return 0;
}


// B
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     string complete;
//     string word;
//     fstream ss("day_3_input.txt");
//     while(ss>>word){
//         complete+=" "+word;
//     }
//     long long res=0;
    
//     bool enabled=true;
//     int mul_ind=complete.find("mul(");
//     while(mul_ind!=string::npos){
//         int do_ind=complete.rfind("do()",mul_ind);
//         int dont_ind=complete.rfind("don't()",mul_ind);
//         if(do_ind!=string::npos && dont_ind!=string::npos){
//             if(do_ind>dont_ind) enabled=true;
//             else if(dont_ind>do_ind) enabled=false;
//         }
//         if(do_ind==string::npos && dont_ind!=string::npos){
//             enabled=false;
//         }

//         if(do_ind!=string::npos && dont_ind==string::npos){
//             enabled=true;
//         }
//         if(enabled) res+=parse(complete,mul_ind);
//         mul_ind=complete.find("mul(",mul_ind+1);
//     }
//     cout<<res<<endl;
//     return 0;
// }