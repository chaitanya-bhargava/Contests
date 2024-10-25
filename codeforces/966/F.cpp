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
       bool operator()(vector<int> a, vector<int> b){
           if(a[0]==b[0]){
            if(a[1]==b[1]){
                return a[2]>b[2];
            }
            return a[1]>b[1];
           }
           return a[0]<b[0];
      }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            int points=0;
            if(a==1 && b==1) points=2;
            else if(a==1 || b==1) points=1;
            pq.push({points,min(a,b),max(a,b)});
        }
        int ans=0;
        int ct=0;
        while(ans<k && !pq.empty()){
            vector<int> temp=pq.top();
            pq.pop();
            cout<<"TEMP:"<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<endl;
            if(temp[0]==0){
                if(temp[1]==2 && temp[2]==2){
                    ans++;
                    ct+=2;
                    pq.push({1,1,2});
                }
                else if(temp[1]==temp[2]){
                    ans++;
                    ct+=temp[1];
                    pq.push({0,temp[1]-1,temp[1]});
                }
                else{
                    ct+=temp[1]*min(temp[2]-temp[1],k-ans);
                    ans+=temp[2]-temp[1];
                    pq.push({0,temp[1],temp[1]});
                }
            }
            else if(temp[0]==1){
                if(temp[2]==2){
                    ans++;
                    ct++;
                    pq.push({2,1,1});
                }
                else{
                    ans++;
                    ct++;
                    pq.push({1,1,temp[2]-1});
                }
            }
            else{
                ans+=2;
                ct++;
            }
        }
        if(ans<k) cout<<-1<<endl;
        else cout<<ct<<endl;
    }
    return 0;
}