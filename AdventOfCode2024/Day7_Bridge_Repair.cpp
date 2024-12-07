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
 
const int n=850;

bool parse1(vector<string> & ops,int i,ll & res,ll curr){
    if(i==ops.size()){
        return curr==res;
    }
    return parse1(ops,i+1,res,curr*stoll(ops[i])) || parse1(ops,i+1,res,curr+stoll(ops[i]));
}

bool parse2(vector<string> & ops,int i,ll & res,ll curr){
    if(i==ops.size()){
        return curr==res;
    }
    return parse2(ops,i+1,res,curr*stoll(ops[i])) || parse2(ops,i+1,res,curr+stoll(ops[i])) || parse2(ops,i+1,res,curr*pow(10,ops[i].size())+stoll(ops[i]));
}

//A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> query(n);
//     for(int i=0;i<n;i++){
//         getline(cin,query[i]);
//     }
//     long long res=0;
//     for(auto x:query){
//         stringstream ss(x);
//         string word;
//         vector<string> ops;
//         while(ss>>word){
//             ops.push_back(word);
//         }
//         ll need = stoll(ops[0].substr(0,ops[0].size()-1));
//         if(parse1(ops,2,need,stoi(ops[1]))) res+=need;
//     }
//     cout<<res<<endl;
//     return 0;
// }

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> query(n);
    for(int i=0;i<n;i++){
        getline(cin,query[i]);
    }
    long long res=0;
    for(auto x:query){
        stringstream ss(x);
        string word;
        vector<string> ops;
        while(ss>>word){
            ops.push_back(word);
        }
        ll need = stoll(ops[0].substr(0,ops[0].size()-1));
        if(parse2(ops,2,need,stoi(ops[1]))) res+=need;
    }
    cout<<res<<endl;
    return 0;
}