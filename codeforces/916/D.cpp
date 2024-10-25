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
        int n;
        cin>>n;
        vector<pii> a(n);
        vector<pii> b(n);
        vector<pii> c(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        for(int i=0;i<n;i++){
            cin>>b[i].first;
            b[i].second=i;
        }
        for(int i=0;i<n;i++){
            cin>>c[i].first;
            c[i].second=i;
        }
        sort(a.begin(),a.end(),greater<pii>());
        sort(b.begin(),b.end(),greater<pii>());
        sort(c.begin(),c.end(),greater<pii>());
        int i=0,j=0,k=0;
        while(a[i].second==b[j].second || a[i].second==c[k].second || c[k].second==b[j].second){
            if(a[i].second==b[j].second && b[j].second==c[k].second){
                if(a[i].first-a[i+1].first<=b[j].first-b[j+1].first && a[i].first-a[i+1].first<=c[k].first-c[k+1].first){
                    i++;
                }
                else if(b[j].first-b[j+1].first<=a[i].first-a[i+1].first && b[j].first-b[j+1].first<=c[k].first-c[k+1].first){
                    j++;
                }
                else{
                    k++;
                }
            }
            else{
                if(a[i].second==b[j].second){
                    if(a[i].first-a[i+1].first>b[j].first-b[j+1].first){
                        j++;
                    }
                    else if(a[i].first-a[i+1].first<b[j].first-b[j+1].first){
                        i++;
                    }
                    else if(a[i+1].second==c[k].second){
                        j++;
                    }
                    else{
                        i++;
                    }
                }
                else if(a[i].second==c[k].second){
                    if(a[i].first-a[i+1].first>c[k].first-c[k+1].first){
                        k++;
                    }
                    else if(a[i].first-a[i+1].first<c[k].first-c[k+1].first){
                        i++;
                    }
                    else if(a[i+1].second==b[j].second){
                        k++;
                    }
                    else{
                        i++;
                    }
                }
                else if(c[k].second==b[j].second){
                    if(c[k].first-c[k+1].first>b[j].first-b[j+1].first){
                        j++;
                    }
                    else if(c[k].first-c[k+1].first<b[j].first-b[j+1].first){
                        k++;
                    }
                    else if(c[k+1].second==a[i].second){
                        j++;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        cout<<a[i].first+b[j].first+c[k].first<<endl;
    }
    return 0;
}