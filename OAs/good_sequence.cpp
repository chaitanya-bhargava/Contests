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
 
long countGoodSubsequences(vector<int> arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int ans=0;
    int curr=1;
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            curr=curr*(count+1);
            if(arr[i]==arr[i-1]+1){
                curr=curr*2+1;
            }
            else{
                ans+=curr;
                curr=1;
            }
            count+1;
        }
    }
    curr=curr*(count+1);
    ans+=curr; 
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res=countGoodSubsequences(a);
    cout<<res<<endl;
    return 0;
}