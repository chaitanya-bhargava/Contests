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
 

class Compare {
    public:
       bool operator()(vector<ll> & a, vector<ll> & b){
           for(int i=0;i<a.size();i++){
            if(a[i]==b[i]) continue;  
            if(i%2==0) return a[i]<b[i];
            else return a[i]>b[i];
           }
           return true;
      }
};

void helper(vector<ll> & a,ll i,vector<ll> & curr,unordered_map<ll,bool> & marked,map<ll,vector<vector<ll>>,greater<ll>> & ans){
    if(i==a.size()){
        ans[curr.size()].push_back(curr);
        return ;
    }
    helper(a,i+1,curr,marked,ans);
    if(!marked[a[i]]){
        marked[a[i]]=true;
        curr.push_back(a[i]);
        helper(a,i+1,curr,marked,ans);
        curr.pop_back();
        marked[a[i]]=false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll> curr;
        unordered_map<ll,bool> marked;
        map<ll,vector<vector<ll>>,greater<ll>> ans;
        helper(a,0,curr,marked,ans);
        vector<vector<ll>> choice=(*ans.begin()).second;    
        priority_queue<vector<ll>,vector<vector<ll>>,Compare> pq;
        for(int i=0;i<choice.size();i++){
            pq.push(choice[i]);
        }
        vector<ll> res=pq.top();
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}