#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        while(k--){
            if(x==y){
                break;
            }
            else{
                if(x>y){
                    x=__gcd(x,y);
                }
                else{
                    y=__gcd(x,y);
                }
                if(x==y) break;
                if(x>y){
                    x=x*y/__gcd(x,y);
                }
                else{
                    y=x*y/__gcd(x,y);
                }
            }
        }
        cout<<x+y<<endl;
    }
    return 0;
}