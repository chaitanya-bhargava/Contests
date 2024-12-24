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
 
const int n=90;

int levelInit(unordered_map<string,int> & level,unordered_map<string,vector<string>> & gate,string wire){
    if(level.count(wire)) return level[wire];
    return 1+max(levelInit(level,gate,gate[wire][1]),levelInit(level,gate,gate[wire][2]));
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
//     unordered_map<string,int> wires;
//     vector<string> wire_labels;
//     unordered_map<string,int> level;
//     for(int i=0;i<n;i++){
//         wires[lines[i].substr(0,3)]=stoi(lines[i].substr(5));
//         level[lines[i].substr(0,3)]=0;
//         wire_labels.push_back(lines[i].substr(0,3));
//     }
//     ll x_in=0;
//     for(auto x:wires){
//         if(x.second==1 && x.first[0]=='x'){
//             ll shift=stoi(x.first.substr(1,2));
//             x_in+=(ll)1<<shift;
//         }
//     }
//     ll y_in=0;
//     for(auto x:wires){
//         if(x.second==1 && x.first[0]=='y'){
//             ll shift=stoi(x.first.substr(1,2));
//             y_in+=(ll)1<<shift;
//         }
//     }
//     unordered_map<string,vector<string>> gate;
//     for(int i=n+1;i<lines.size();i++){
//         string a = lines[i].substr(0,3);
//         string g = lines[i].substr(4,2);
//         string b;
//         string c;
//         if(g!="OR"){
//             g = lines[i].substr(4,3);
//             b = lines[i].substr(8,3);
//             c = lines[i].substr(15,3);
//         }
//         else{
//             b = lines[i].substr(7,3);
//             c = lines[i].substr(14,3);
//         }
//         gate[c]={g,a,b};
//         wire_labels.push_back(c);
//         wires[c]=-1;
//     }
//     for(auto x:wires){
//         level[x.first]=levelInit(level,gate,x.first);
//     }

//     queue<string> q;
//     for (auto x:level){
//         if(x.second==1){
//             q.push(x.first);
//             level.erase(x.first);
//         }
//     }
//     int curr_level=1;
//     while(!q.empty()){
//         int sz=q.size();
//         for(int i=0;i<sz;i++){
//             string op = q.front();
//             q.pop();
//             if(gate[op][0]=="AND"){
//                 wires[op]=wires[gate[op][1]] & wires[gate[op][2]];
//             }
//             else if(gate[op][0]=="XOR"){
//                 wires[op]=wires[gate[op][1]] ^ wires[gate[op][2]];
//             }
//             else if(gate[op][0]=="OR"){
//                 wires[op]=wires[gate[op][1]] | wires[gate[op][2]];
//             }
//         }
//         curr_level++;
//         for (auto x:level){
//             if(x.second==curr_level){
//                 q.push(x.first);
//                 level.erase(x.first);
//             }
//         }
//     }
//     ll res=0;
//     for(auto x:wires){
//         if(x.second==1 && x.first[0]=='z'){
//             ll shift=stoi(x.first.substr(1,2));
//             res+=(ll)1<<shift;
//         }
//     }
//     cout<<x_in<<" "<<y_in<<" "<<res<<endl;
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
    unordered_map<string,int> wires;
    vector<string> wire_labels;
    unordered_map<string,int> level;
    for(int i=0;i<n;i++){
        wires[lines[i].substr(0,3)]=stoi(lines[i].substr(5));
        level[lines[i].substr(0,3)]=0;
        wire_labels.push_back(lines[i].substr(0,3));
    }
    ll x_in=0;
    for(auto x:wires){
        if(x.second==1 && x.first[0]=='x'){
            ll shift=stoi(x.first.substr(1,2));
            x_in+=(ll)1<<shift;
        }
    }
    ll y_in=0;
    for(auto x:wires){
        if(x.second==1 && x.first[0]=='y'){
            ll shift=stoi(x.first.substr(1,2));
            y_in+=(ll)1<<shift;
        }
    }
    unordered_map<string,vector<string>> gate;
    for(int i=n+1;i<lines.size();i++){
        string a = lines[i].substr(0,3);
        string g = lines[i].substr(4,2);
        string b;
        string c;
        if(g!="OR"){
            g = lines[i].substr(4,3);
            b = lines[i].substr(8,3);
            c = lines[i].substr(15,3);
        }
        else{
            b = lines[i].substr(7,3);
            c = lines[i].substr(14,3);
        }
        gate[c]={g,a,b};
        wire_labels.push_back(c);
        wires[c]=-1;
    }
    int max_level=0;
    for(auto x:wires){
        level[x.first]=levelInit(level,gate,x.first);
        max_level=max(max_level,level[x.first]);
    }

    set<string> faulty;
    for(auto x:wires){
        if(x.first[0]!='z' && level[x.first]!=0 && level[x.first]!=1 && gate[x.first][0]=="XOR"){
            faulty.insert(x.first);
        }
        else if (x.first[0]=='z' && level[x.first]!=88 && gate[x.first][0]!="XOR"){
            faulty.insert(x.first);
        } 
        else if (level[x.first]>1 && gate[x.first][0]=="OR"){
            if(gate[gate[x.first][1]][0]!="AND"){
                faulty.insert(gate[x.first][1]);
            }
            if(gate[gate[x.first][2]][0]!="AND"){
                faulty.insert(gate[x.first][2]);
            }
        } 
        else if (level[x.first]>2 && gate[x.first][0]=="XOR"){ // skip level 1 because the carry no. 1 is just AND gate not OR of 2 AND gates
            if(gate[gate[x.first][1]][0]=="AND"){
                faulty.insert(gate[x.first][1]);
            }
            if(gate[gate[x.first][2]][0]=="AND"){
                faulty.insert(gate[x.first][2]);
            }
        } 
    }

    for(auto x:faulty){
        cout<<x<<",";
    }
    return 0;
}