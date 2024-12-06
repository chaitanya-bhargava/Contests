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
 
// const int n=21;
// const int m=6;
const int n=1176;
const int m=196;

//A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     map<int,map<int,int>> grid;
//     unordered_map<int,int> indegree;
//     for(int i=0;i<n;i++){
//         string inp;
//         cin>>inp;
//         int ind=inp.find('|');
//         int num1=stoi(inp.substr(0,ind));
//         int num2=stoi(inp.substr(ind+1,inp.size()-ind-1));
//         grid[num1][num2]=1;
//     }

//     long long res=0;

//     for(int k=0;k<m;k++){
//         string str;
//         cin>>str;

//         stringstream ss(str);
//         string word;

//         vector<int> query;
//         while(!ss.eof()){
//             getline(ss,word,',');
//             query.push_back(stoi(word));
//         }
//         int flag=0;
//         for(int i=0;i<query.size();i++){
//             for(int j=i+1;j<query.size();j++){
//                 if(grid[query[j]][query[i]]==1){
//                     flag=1;
//                     break;
//                 }
//             }
//             if(flag==1) break;
//         }
//         // cout<<k<<" "<<flag<<" "<<res<<endl;
//         if(flag==0) res+=query[query.size()/2];
//     }
    
//     cout<<res<<endl;

//     return 0;
// }

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,map<int,int>> grid;
    unordered_map<int,int> indegree;
    for(int i=0;i<n;i++){
        string inp;
        cin>>inp;
        int ind=inp.find('|');
        int num1=stoi(inp.substr(0,ind));
        int num2=stoi(inp.substr(ind+1,inp.size()-ind-1));
        grid[num1][num2]=1;
    }

    long long res=0;

    for(int k=0;k<m;k++){
        string str;
        cin>>str;

        stringstream ss(str);
        string word;

        vector<int> query;
        while(!ss.eof()){
            getline(ss,word,',');
            query.push_back(stoi(word));
        }
        int flag=0;
        for(int i=0;i<query.size()-1;i++){
            for(int j=0;j<query.size()-i-1;j++){
                if(grid[query[j+1]][query[j]]==1){
                    flag=1;
                    swap(query[j+1],query[j]);
                }
            }
        }
        if(flag==1) res+=query[query.size()/2];
    }
    
    cout<<res<<endl;

    return 0;
}