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
//     string s;
//     cin>>s;
//     vector<long long> mp;
//     long long id=0;
//     for(long long i=0;i<s.size();i++){
//         long long ct=s[i]-'0';
//         if(i%2==0){
//             while(ct--){
//                 mp.push_back(id);
//             }
//             id++;
//         } 
//         else{
//             while(ct--){
//                 mp.push_back(-1);
//             }
//         }
//     }
//     long long r=mp.size()-1;
//     long long l=0;
//     while(mp[l]!=-1) l++;
//     while(mp[r]==-1) r--;
//     while(l<r){
//         mp[l]=mp[r];
//         mp[r]=-1;
//         while(mp[l]!=-1) l++;
//         while(mp[r]==-1) r--;
//     }
//     long long res=0;
//     for(long long i=0;i<mp.size();i++){
//         if(mp[i]!=-1) res+=i*mp[i];
//     }
//     cout<<res<<endl;
//     return 0;
// }

//B
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    vector<long long> mp;
    long long id=0;
    for(long long i=0;i<s.size();i++){
        long long ct=s[i]-'0';
        if(i%2==0){
            while(ct--){
                mp.push_back(id);
            }
            id++;
        } 
        else{
            while(ct--){
                mp.push_back(-1);
            }
        }
    }
    int n=mp.size();
    id=mp[n-1];
    while(id!=0){
        int blocklen=0;
        int rev_find=find(mp.rbegin(),mp.rend(),id)-mp.rbegin();
        int r=n-rev_find-1;
        int tempr=r;
        while(mp[tempr]==id){
            blocklen++;
            tempr--;
        }
        int space_id=find(mp.begin(),mp.end(),-1)-mp.begin();
        int templ=space_id;
        int space_len=0;
        while(mp[templ]==-1){
            templ++;
            space_len++;
        }
        // cout<<id<<" "<<space_id<<" "<<space_len<<" "<<tempr+1<<" "<<blocklen<<endl;
        while(space_id<n && space_len<blocklen){
            space_id=find(mp.begin()+templ,mp.end(),-1)-mp.begin();
            templ=space_id;
            space_len=0;
            while(mp[templ]==-1){
                templ++;
                space_len++;
            }   
        }
        tempr++;
        if(space_id+space_len<=tempr){
            int k=0;
            templ=space_id;
            while(k<blocklen){
                mp[templ]=mp[tempr];
                mp[tempr]=-1;
                templ++;
                tempr++;
                k++;
            }
        }
        id--;
    }
    long long res=0;
    for(long long i=0;i<mp.size();i++){
        if(mp[i]!=-1) res+=i*mp[i];
    }
    cout<<res<<endl;
    return 0;
}