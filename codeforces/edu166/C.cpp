#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define V vector
#define pb push_back
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
        long long n,m;
        cin>>n>>m;
        vector<long long> p(n+m+1);
        vector<long long> t(n+m+1);
        vector<long long> pf(n+m+1,0);
        vector<long long> tf(n+m+1,0);
        if(n==0){
            long long p_sum=0;
            for(long long i=0;i<n+m+1;i++){
                cin>>p[i];
                p_sum+=p[i];
            }
            long long t_sum=0;
            for(long long i=0;i<n+m+1;i++){
                cin>>t[i];
                t_sum+=t[i];
            }
            for(long long i=0;i<m+1;i++){
                cout<<t_sum-t[i]<<" ";
            }
            cout<<endl;
        }
        else if(m==0){
            long long p_sum=0;
            for(long long i=0;i<n+m+1;i++){
                cin>>p[i];
                p_sum+=p[i];
            }
            long long t_sum=0;
            for(long long i=0;i<n+m+1;i++){
                cin>>t[i];
                t_sum+=t[i];
            }
            for(long long i=0;i<n+1;i++){
                cout<<p_sum-p[i]<<" ";
            }
            cout<<endl;
        }
        else{
            long long count; 
            long long use;
            if(n<m){
                count=n;
                use=0;
            }
            else{
                count=m;
                use=1;
            }
            if(use==0){
                long long p_sum=0;
                for(long long i=0;i<n+m+1;i++){
                    cin>>p[i];
                    p_sum+=p[i];
                }
                long long t_sum=0;
                long long curr=0;
                long long extra=-1;
                for(long long i=0;i<n+m+1;i++){
                    cin>>t[i];
                    t_sum+=t[i];
                    if(count>0){
                        if(p[i]>t[i]){
                            pf[i]=1;
                            count--;
                            curr+=p[i]-t[i];
                        }
                    }
                    else if(count==0){
                        if(p[i]>t[i]){
                            extra=i;
                            count--;
                        }
                    }
                }
                if(count>0){
                    long long i=n+m;
                    while(count>0){
                        if(pf[i]==0){
                            pf[i]=1;
                            count--;
                            curr+=p[i]-t[i];
                        }
                        i--;
                    }
                    while(count==0){
                        if(pf[i]==0){
                            extra=i;
                            count--;
                        }
                        i--;
                    }
                }
                if(count==0){
                    long long i=n+m;
                    while(count==0){
                        if(pf[i]==0){
                            extra=i;
                            count--;
                        }
                        i--;
                    }
                }
                for(long long i=0;i<n+m+1;i++){
                    if(pf[i]==1){
                        cout<<t_sum-t[extra]+p[extra]+curr-p[i]<<" ";
                    }
                    else{
                        cout<<t_sum+curr-t[i]<<" ";
                    }
                }
                cout<<endl;
            }
            else{
                long long p_sum=0;
                for(long long i=0;i<n+m+1;i++){
                    cin>>p[i];
                    p_sum+=p[i];
                }
                long long t_sum=0;
                long long curr=0;
                long long extra=-1;
                for(long long i=0;i<n+m+1;i++){
                    cin>>t[i];
                    t_sum+=t[i];
                    if(count>0){
                        if(p[i]<t[i]){
                            tf[i]=1;
                            count--;
                            curr+=t[i]-p[i];
                        }
                    }
                    else if(count==0){
                        if(p[i]<t[i]){
                            extra=i;
                            count--;
                        }
                    }
                }
                if(count>0){
                    long long i=n+m;
                    while(count>0){
                        if(tf[i]==0){
                            tf[i]=1;
                            count--;
                            curr+=t[i]-p[i];
                        }
                        i--;
                    }
                    while(count==0){
                        if(tf[i]==0){
                            extra=i;
                            count--;
                        }
                        i--;
                    }
                }
                if(count==0){
                    long long i=n+m;
                    while(count==0){
                        if(tf[i]==0){
                            extra=i;
                            count--;
                        }
                        i--;
                    }
                }
                for(long long i=0;i<n+m+1;i++){
                    if(tf[i]==1){
                        cout<<p_sum-p[extra]+t[extra]+curr-t[i]<<" ";
                    }
                    else{
                        cout<<p_sum+curr-p[i]<<" ";
                    }
                }
                cout<<endl;
            }
        }
    }
    return 0;
}