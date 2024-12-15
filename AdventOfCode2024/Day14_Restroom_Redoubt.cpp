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
 
const int n=101;
const int m=103;

//A
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     vector<string> lines;
//     fstream ss("input.txt");
//     string line;
//     while(getline(ss,line)){
//         lines.push_back(line);
//     }
//     int quad1=0;
//     int quad2=0;
//     int quad3=0;
//     int quad4=0;
//     for(int i=0;i<lines.size();i++){
//         int x=stoi(lines[i].substr(lines[i].find('=')+1));
//         int y=stoi(lines[i].substr(lines[i].find(',')+1));
//         int v_ind=lines[i].find("v=");
//         int vx=stoi(lines[i].substr(v_ind+2));
//         int vy=stoi(lines[i].substr(lines[i].find(',',v_ind)+1));
//         // cout<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
//         int newx=((x+vx*100)%n+n)%n;
//         int newy=((y+vy*100)%m+m)%m;
//         if(newx<(n/2) && newy<(m/2)) quad1++;
//         if(newx>(n/2) && newy<(m/2)) quad2++;
//         if(newx<(n/2) && newy>(m/2)) quad3++;
//         if(newx>(n/2) && newy>(m/2)) quad4++;
//         // cout<<newx<<" "<<newy<<" "<<quad1<<" "<<quad2<<" "<<quad3<<" "<<quad4<<endl;
//     }
//     ll res=quad1*quad2*quad3*quad4;
//     cout<<res<<endl;
//     return 0;
// }

//B
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
    vector<vector<char>> grid(m,vector<char> (n,'.'));
    for(int j=0;j<=10000;j++){
        vector<vector<char>> grid(m,vector<char> (n,'.'));
        for(int i=0;i<lines.size();i++){
            int x=stoi(lines[i].substr(lines[i].find('=')+1));
            int y=stoi(lines[i].substr(lines[i].find(',')+1));
            int v_ind=lines[i].find("v=");
            int vx=stoi(lines[i].substr(v_ind+2));
            int vy=stoi(lines[i].substr(lines[i].find(',',v_ind)+1));
            int newx=((x+vx*j)%n+n)%n;
            int newy=((y+vy*j)%m+m)%m;
            grid[newy][newx]='O';
        }
        sso<<"J: "<<j<<endl;
        for(int l=0;l<m;l++){
            for(int r=0;r<n;r++){
                sso<<grid[l][r];
            }
            sso<<endl;
        }
        sso<<endl;
    }
    return 0;
}