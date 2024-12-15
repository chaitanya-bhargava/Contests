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
//     int sz=lines.size()/4;

//     ll res=0;

//     for(int i=0;i<sz;i++){
//         string aline=lines[i*4];
//         string bline=lines[i*4+1];
//         string przline=lines[i*4+2];
//         // cout<<aline<<endl;
//         // cout<<bline<<endl;
//         // cout<<przline<<endl;
//         int plus_ind=aline.find('+');
//         int comma_ind=aline.find(',');
//         int xa=stoi(aline.substr(plus_ind+1,comma_ind-plus_ind-1));
//         plus_ind=aline.find('+',comma_ind);
//         int ya=stoi(aline.substr(plus_ind+1,aline.size()-plus_ind-1));
//         plus_ind=bline.find('+');
//         comma_ind=bline.find(',');
//         int xb=stoi(bline.substr(plus_ind+1,comma_ind-plus_ind-1));
//         plus_ind=bline.find('+',comma_ind);
//         int yb=stoi(bline.substr(plus_ind+1,bline.size()-plus_ind-1));
//         plus_ind=przline.find('=');
//         comma_ind=przline.find(',');
//         int xp=stoi(przline.substr(plus_ind+1,comma_ind-plus_ind-1));
//         plus_ind=przline.find('=',comma_ind);
//         int yp=stoi(przline.substr(plus_ind+1,przline.size()-plus_ind-1));

//         int tokens=INT_MAX;

//         for(int j=1;j<=100;j++){
//             for(int k=1;k<=100;k++){
//                 if((xa*j+xb*k)==xp && (ya*j+yb*k)==yp){
//                     tokens=min(tokens,3*j+k);
//                 }
//             }
//         }

//         if(tokens!=INT_MAX){
//             res+=tokens;
//         }

//     }
//     cout<<res<<endl;

//     return 0;
// }


pair<double,double> solveSystemOfEquations(vector<vector<double>> system) {
    double D = (system[0][0] * system[1][1]) - (system[1][0] * system[0][1]);
    double Dx = (system[0][2] * system[1][1]) - (system[1][2] * system[0][1]);
    double Dy = (system[0][0] * system[1][2]) - (system[1][0] * system[0][2]);
 
    double x = Dx / D;
    double y = Dy / D;
 
    return {x, y};
}

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> lines;
    fstream ss("input.txt");
    string line;
    while(getline(ss,line)){
        lines.push_back(line);
    }
    int sz=lines.size()/4;

    ll res=0;

    for(int i=0;i<=sz;i++){
        string aline=lines[i*4];
        string bline=lines[i*4+1];
        string przline=lines[i*4+2];
        // cout<<aline<<endl;
        // cout<<bline<<endl;
        // cout<<przline<<endl;
        int plus_ind=aline.find('+');
        int comma_ind=aline.find(',');
        double xa=stoi(aline.substr(plus_ind+1,comma_ind-plus_ind-1));
        plus_ind=aline.find('+',comma_ind);
        double ya=stoi(aline.substr(plus_ind+1,aline.size()-plus_ind-1));
        plus_ind=bline.find('+');
        comma_ind=bline.find(',');
        double xb=stoi(bline.substr(plus_ind+1,comma_ind-plus_ind-1));
        plus_ind=bline.find('+',comma_ind);
        double yb=stoi(bline.substr(plus_ind+1,bline.size()-plus_ind-1));
        plus_ind=przline.find('=');
        comma_ind=przline.find(',');
        double xp=stoi(przline.substr(plus_ind+1,comma_ind-plus_ind-1));
        plus_ind=przline.find('=',comma_ind);
        double yp=stoi(przline.substr(plus_ind+1,przline.size()-plus_ind-1));

        xp+=10000000000000;
        yp+=10000000000000;

        pair<double,double> temp=solveSystemOfEquations({{xa,xb,xp},{ya,yb,yp}});

        if((ull)temp.first==temp.first && (ull)temp.second==temp.second){
            res+=3*temp.first+temp.second;
        }

    }
    cout<<res<<endl;

    return 0;
}