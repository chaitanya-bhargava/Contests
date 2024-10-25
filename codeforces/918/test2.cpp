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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        unordered_map<char,int> m1,m2,m3;
        int flag1=0,flag2=0,flag3=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='?'){
                flag1=1;
            }
            m1[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='?'){
                flag2=1;
            }
            m2[s2[i]]++;
        }
        for(int i=0;i<s3.size();i++){
            if(s3[i]=='?'){
                flag3=1;
            }
            m3[s3[i]]++;
        }
        if(flag1==1){
            if(m1['A']==m1['B']){
                cout<<'C'<<endl;
                continue;
            }
            if(m1['A']==m1['C']){
                cout<<'B'<<endl;
                continue;
            }
            if(m1['C']==m1['B']){
                cout<<'A'<<endl;
                continue;
            }
        }
        if(flag2==1){
            if(m2['A']==m2['B']){
                cout<<'C'<<endl;
                continue;
            }
            if(m2['A']==m2['C']){
                cout<<'B'<<endl;
                continue;
            }
            if(m2['C']==m2['B']){
                cout<<'A'<<endl;
                continue;
            }
        }
        if(flag3==1){
            if(m3['A']==m3['B']){
                cout<<'C'<<endl;
                continue;
            }
            if(m3['A']==m3['C']){
                cout<<'B'<<endl;
                continue;
            }
            if(m3['C']==m3['B']){
                cout<<'A'<<endl;
                continue;
            }
        }
    }
    return 0;
}