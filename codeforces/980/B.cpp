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
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int i=0;
        int ct=0;
        int ans=0;
        while(k>=(n-i)){
            cout<<k<<" "<<i<<" "<<ans<<" "<<ct<<endl;
            k-=(n-i);
            ct++;
            ans+=(n-i);
            if(arr[i]==ct+1){
                i++;
            }
        }
        while(k>0){
            ans+=min(k,arr[i]+1);
            k-=min(k,arr[i]);
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}