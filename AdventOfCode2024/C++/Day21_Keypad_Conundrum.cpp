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
 
string numpad_helper(unordered_map<char,pair<ll,ll>> & numpad,string & target){
    string ans;
    ll x=3;
    ll y=2;
    for(auto it:target){
        string temp;
        ll tempx=x;
        ll tempy=y;
        ll newx=numpad[it].first;
        ll newy=numpad[it].second;
        if(x==3 && newx<3 && y>0 && newy==0){
            while(x!=newx){
                temp+='^';
                x--;
            }
            while(y!=newy){
                temp+='<';
                y--;
            }
        }
        if(x<3 && newx==3 && y==0 && newy>0){
            while(y!=newy){
                temp+='>';
                y++;
            }
            while(x!=newx){
                temp+='v';
                x++;
            }
        }
        if(newy<y){
            while(y!=newy){
                temp+='<';
                y--;
            }
        }
        if(newx<x){
            while(x!=newx){
                temp+='^';
                x--;
            }
        }
        if(newx>x){
            while(x!=newx){
                temp+='v';
                x++;
            }
        }
        if(newy>y){
            while(y!=newy){
                temp+='>';
                y++;
            }
        }
        temp+='A';
        ans+=temp;
    }
    return ans;
}

ll dirpad_helper(map<pair<char,char>,string> & dirpad,string & target,ll layer,map<pair<string,ll>,ll> & memo){
    if(layer==25) return target.size();
    if(memo.count({target,layer})){
        return memo[{target,layer}];
    }
    char curr='A';
    ll ans=0;
    for(auto x:target){
        string path=dirpad[{curr,x}];
        ans+=dirpad_helper(dirpad,path,layer+1,memo);
        curr=x;
    }
    return memo[{target,layer}]=ans;
}

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
    unordered_map<char,pair<ll,ll>> numpad;
    numpad['0']={3,1};
    numpad['1']={2,0};
    numpad['2']={2,1};
    numpad['3']={2,2};
    numpad['4']={1,0};
    numpad['5']={1,1};
    numpad['6']={1,2};
    numpad['7']={0,0};
    numpad['8']={0,1};
    numpad['9']={0,2};
    numpad['A']={3,2};
    map<pair<char,char>,string> dirpad;
    dirpad[{'A','A'}]="A";
    dirpad[{'A','^'}]="<A";
    dirpad[{'A','>'}]="vA";
    dirpad[{'A','v'}]="<vA";
    dirpad[{'A','<'}]="v<<A";
    dirpad[{'^','^'}]="A";
    dirpad[{'^','A'}]=">A";
    dirpad[{'^','v'}]="vA";
    dirpad[{'^','>'}]="v>A";
    dirpad[{'^','<'}]="v<A";
    dirpad[{'>','>'}]="A";
    dirpad[{'>','A'}]="^A";
    dirpad[{'>','v'}]="<A";
    dirpad[{'>','^'}]="<^A";
    dirpad[{'>','<'}]="<<A";
    dirpad[{'v','v'}]="A";
    dirpad[{'v','<'}]="<A";
    dirpad[{'v','>'}]=">A";
    dirpad[{'v','^'}]="^A";
    dirpad[{'v','A'}]="^>A";
    dirpad[{'<','<'}]="A";
    dirpad[{'<','v'}]=">A";
    dirpad[{'<','>'}]=">>A";
    dirpad[{'<','^'}]=">^A";
    dirpad[{'<','A'}]=">>^A";
    ll res=0;
    map<pair<string,ll>,ll> memo;
    for(auto x:lines){
        string robot1=numpad_helper(numpad,x);
        ll temp=dirpad_helper(dirpad,robot1,0,memo);
        ll val=stoi(x);
        res+=temp*val;
    }
    cout<<res<<endl;
    return 0;
}