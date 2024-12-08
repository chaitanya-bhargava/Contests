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
 
const int n=50;

//A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> grid(n);
//     for(int i=0;i<n;i++){
//         cin>>grid[i];
//     }

//     unordered_map<char,vector<pair<int,int>>> mp;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]!='.') mp[grid[i][j]].push_back({i,j});
//         }
//     }
//     long long res=0;
//     set<pair<int,int>> s1;
//     for(auto it:mp){
//         for(int i=0;i<it.second.size();i++){
//             for(int j=i+1;j<it.second.size();j++){
//                 int x1=it.second[i].first;
//                 int y1=it.second[i].second;
//                 int x2=it.second[j].first;
//                 int y2=it.second[j].second;
//                 int antix1=2*x1-x2;
//                 int antiy1=2*y1-y2;
//                 int antix2=2*x2-x1;
//                 int antiy2=2*y2-y1;
//                 if(antix1>=0 && antiy1>=0 && antix1<n && antiy1<n) s1.insert({antix1,antiy1});
//                 if(antix2>=0 && antiy2>=0 && antix2<n && antiy2<n) s1.insert({antix2,antiy2});
//             }
//         }
//     }
//     cout<<s1.size()<<endl;

//     return 0;
// }

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    unordered_map<char,vector<pair<int,int>>> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!='.') mp[grid[i][j]].push_back({i,j});
        }
    }
    long long res=0;
    set<pair<int,int>> s1;
    for(auto it:mp){
        for(int i=0;i<it.second.size();i++){
            for(int j=i+1;j<it.second.size();j++){
                int x1=it.second[i].first;
                int y1=it.second[i].second;
                int x2=it.second[j].first;
                int y2=it.second[j].second;
                s1.insert({x1,y1});
                s1.insert({x2,y2});
                int i=1;
                int antix1=x1-i*(x2-x1);
                int antiy1=y1-i*(y2-y1);
                while(antix1>=0 && antiy1>=0 && antix1<n && antiy1<n){
                    s1.insert({antix1,antiy1});
                    i++;
                    antix1=x1-i*(x2-x1);
                    antiy1=y1-i*(y2-y1);
                }
                i=1;
                int antix2=x2+i*(x2-x1);
                int antiy2=y2+i*(y2-y1);
                while(antix2>=0 && antiy2>=0 && antix2<n && antiy2<n){
                    s1.insert({antix2,antiy2});
                    i++;
                    antix2=x2+i*(x2-x1);
                    antiy2=y2+i*(y2-y1);
                }
            }
        }
    }

    // for(auto it:s1){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    cout<<s1.size()<<endl;

    return 0;
}