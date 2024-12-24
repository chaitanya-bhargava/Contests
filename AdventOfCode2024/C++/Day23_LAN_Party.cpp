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
//     map<pair<string,string>,bool> edges;
//     map<string,vector<string>> g1;
//     for(auto x:lines){
//         string a=x.substr(0,2);
//         string b=x.substr(3,2);
//         g1[a].push_back(b);
//         g1[b].push_back(a);
//         if(a<b){
//             edges[{a,b}]=true;
//         }
//         else{
//             edges[{b,a}]=true;
//         }
//     }
//     ll res=0;
//     set<vector<string>> s1;
//     for(auto it:edges){
//         if(it.second && (it.first.first[0]=='t' || it.first.second[0]=='t')){
//             string c1=it.first.first;
//             string c2=it.first.second;
//             if(c1==c2) continue;
//             for(auto x:g1[c2]){
//                 if(edges[{x,c1}] || edges[{c1,x}]){
//                     vector<string> temp={c1,c2,x};
//                     sort(temp.begin(),temp.end());
//                     s1.insert(temp);
//                 }
//             }
//         }
//     }
//     cout<<s1.size()<<endl;
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
    map<pair<string,string>,bool> edges;
    map<string,vector<string>> g1;
    for(auto x:lines){
        string a=x.substr(0,2);
        string b=x.substr(3,2);
        g1[a].push_back(b);
        g1[b].push_back(a);
        if(a<b){
            edges[{a,b}]=true;
        }
        else{
            edges[{b,a}]=true;
        }
    }
    set<vector<string>> s1;
    for(auto it:edges){
        if(it.second && (it.first.first[0]=='t' || it.first.second[0]=='t')){
            string c1=it.first.first;
            string c2=it.first.second;
            if(c1==c2) continue;
            for(auto x:g1[c2]){
                if(edges[{x,c1}] || edges[{c1,x}]){
                    vector<string> temp={c1,c2,x};
                    sort(temp.begin(),temp.end());
                    s1.insert(temp);
                }
            }
        }
    }
    map<int,set<vector<string>>> cliques;
    cliques[3] = s1;

    for (int k = 3; k < 1000; ++k) { 
        for (auto clique : cliques[k]) {
            for (auto node : g1[clique.back()]) { 
                if (find(clique.begin(), clique.end(), node) != clique.end()) continue;

                bool isClique = true;
                for (auto existingNode : clique) {
                    if (!edges[{min(node, existingNode), max(node, existingNode)}]) {
                        isClique = false;
                        break;
                    }
                }

                if (isClique) {
                    vector<string> newClique = clique;
                    newClique.push_back(node);
                    sort(newClique.begin(), newClique.end());
                    cliques[k + 1].insert(newClique);
                }
            }
        }
    }

    int max_clique=3;
    for (int k = 3; k <= 1000; ++k) {
        if(cliques[k].size()>0) max_clique=max(max_clique,k);
    }

    string res;
    for(auto x:cliques[max_clique]){
        for(auto y:x){
            res=res+y+",";
        }
    }
    res.pop_back();
    cout<<res<<endl;
    return 0;
}